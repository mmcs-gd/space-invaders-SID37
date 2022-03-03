#include <SDL2/SDL.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <emscripten.h>

#include <iostream>


SDL_Window *window;

int width;
int height;

GLuint Program;
GLint Attrib_vertex;

GLuint VBO;



struct Vertex {
	GLfloat x;
	GLfloat y;
};


const char *VertexShaderSource = R"(#version 300 es

	in vec2 coord;
	void main() {
		gl_Position = vec4(coord, 0.0, 1.0);
	}
)";

const char *FragShaderSource = R"(#version 300 es

	precision lowp float;

	out vec4 color;

	void main() {
		color = vec4(0, 1, 0, 1);
	}
)";


int InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

	SDL_Rect rect;
	SDL_GetDisplayUsableBounds(0, &rect);
	width = rect.w;
	height = rect.h;
	window = SDL_CreateWindow("Green square", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	if (window == NULL)
	{
		return 1;
	}

	return 0;
}

void Init();
void Draw();
void Release();
void UpdateScene();




void update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				break;
			}
			break;
		}
	}
	glClear(GL_COLOR_BUFFER_BIT);
	Draw();
	SDL_GL_SwapWindow(window);
}


int main(int argc, char **argv)
{
	if (InitSDL())
	{
		return 1;
	}

	Init();

	emscripten_set_main_loop(update, 0, 1);

	Release();
	SDL_Quit();
	return 0;
}


void checkOpenGLerror()
{
	GLenum errCode;
	if ((errCode = glGetError()) != GL_NO_ERROR)
		std::cout << "OpenGl error!: " << errCode << std::endl;
}


void ShaderLog(unsigned int shader)
{
	int infologLen = 0;
	int charsWritten = 0;
	char *infoLog;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infologLen);
	if (infologLen > 1)
	{
		infoLog = new char[infologLen];
		if (infoLog == NULL)
		{
			std::cout << "ERROR: Could not allocate InfoLog buffer" << std::endl;
			exit(1);
		}
		glGetShaderInfoLog(shader, infologLen, &charsWritten, infoLog);
		std::cout << "InfoLog: " << infoLog << "\n\n\n";
		delete[] infoLog;
	}
}


void InitVBO()
{
	glGenBuffers(1, &VBO);

	float min_direction = float(std::min(width, height));
	float x_multipler = min_direction / width;
	float y_multipler = min_direction / height;
	Vertex triangle[6] = {
		{-x_multipler, -y_multipler},
		{-x_multipler,  y_multipler},
		{ x_multipler,  y_multipler},
		{ x_multipler,  y_multipler},
		{ x_multipler, -y_multipler},
		{-x_multipler, -y_multipler}
	};

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	glFlush();
	checkOpenGLerror();
}



void InitShader()
{
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &VertexShaderSource, NULL);
	glCompileShader(vShader);
	std::cout << "vertex shader \n";
	ShaderLog(vShader);

	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &FragShaderSource, NULL);
	glCompileShader(fShader);
	std::cout << "fragment shader \n";
	ShaderLog(fShader);

	Program = glCreateProgram();
	glAttachShader(Program, vShader);
	glAttachShader(Program, fShader);

	glLinkProgram(Program);
	int link_ok;
	glGetProgramiv(Program, GL_LINK_STATUS, &link_ok);
	if (!link_ok)
	{
		std::cout << "error attach shaders \n";
		return;
	}

	const char *attr_name = "coord";
	Attrib_vertex = glGetAttribLocation(Program, attr_name);
	if (Attrib_vertex == -1)
	{
		std::cout << "could not bind attrib " << attr_name << std::endl;
		return;
	}

	checkOpenGLerror();
}


void Init()
{
	InitShader();
	InitVBO();
}


void Draw()
{
	glUseProgram(Program);
	glEnableVertexAttribArray(Attrib_vertex);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(Attrib_vertex, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(Attrib_vertex);
	glUseProgram(0);
	checkOpenGLerror();
}


void ReleaseShader()
{
	glUseProgram(0);
	glDeleteProgram(Program);
}


void ReleaseVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBO);
}


void Release()
{
	ReleaseShader();
	ReleaseVBO();
}
