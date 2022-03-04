const glob = require("glob");
const path = require('path');
const { exec } = require('child_process');
const { exit } = require("process");


const dirname = process.argv[2]
const mode = process.argv[3]
const output_js = process.argv[4]


const flag_list = {
    "release": "-O3 -s USE_SDL=2 -s MIN_WEBGL_VERSION=2 -s MAX_WEBGL_VERSION=2",
    "debug": "-g -o dist/index.js -s USE_SDL=2 -s MIN_WEBGL_VERSION=2 -s MAX_WEBGL_VERSION=2"
};

if (process.argv.includes("-h") || process.argv.length < 5) {
    console.log("node build.js <source_dir> <build_mode> <output_file>");
    console.log("    source_dir   -  directory with .cpp files");
    console.log("    build_mode   -  debug|release");
    console.log("    output_file  -  output .js file");
    exit()
}

if (!(mode in flag_list)) {
    console.log(`error: unknown build mode "${mode}"`);
    exit();
}

glob(path.join(dirname, '/**/*.cpp'), function(err, files) {
    if (err) {
        console.log(`read files error: ${err}`)
        return;
    }

    exec([
            "em++",
            files.join(" "),
            `-o ${output_js}`,
            flag_list[mode]
        ].join(" "),
        (err, stdout, stderr) => {
            console.log(stdout);
            console.log(stderr);
            if (err) {
                console.log(`exec error: ${err}`);
            }
        });
});