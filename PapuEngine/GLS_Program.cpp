#include "GLS_Program.h"



GLS_Program::GLS_Program(): _programID(0) , _vertexShaderID(0), _fragmentShaderID(0)
{
}


void GLS_Program::compileShaders(const string& vertexShaderFilePath,
	const string& fragmentShaderFilePath) {

}

void GLS_Program::compileShader(const string& shaderPath, GLuint id) {
}


GLS_Program::~GLS_Program()
{
}
