#pragma once
#ifndef SHADER_H
#define SHADER_H

#include<glad\glad.h>
#include <string>
#include <iostream>
#include <glm/glm.hpp>

class Shader
{
public:
	// the program ID
	unsigned int program;

	// constructor reads and builds the shader
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// use/activate the shader
	void use();
	// utility uniform functions
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

	void setVec2(const std::string & name, const glm::vec2 & value) const;

	void setVec2(const std::string & name, float x, float y) const;

	void setVec3(const std::string & name, const glm::vec3 & value) const;

	void setVec3(const std::string & name, float x, float y, float z) const;

	void setVec4(const std::string & name, const glm::vec4 & value) const;

	void setVec4(const std::string & name, float x, float y, float z, float w);

	void setMat2(const std::string & name, const glm::mat2 & mat) const;

	void setMat3(const std::string & name, const glm::mat3 & mat) const;

	void setMat4(const std::string & name, const glm::mat4 & mat) const;


private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	void checkCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}

};

#endif
