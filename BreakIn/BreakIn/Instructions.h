#ifndef _INSTRUCTIONS_INCLUDE
#define _INSTRUCTIONS_INCLUDE

#include "ShaderProgram.h"
#include "Texture.h"
#include "TexturedQuad.h"
#include <glm/glm.hpp>


#define CAMERA_WIDTH 640
#define CAMERA_HEIGHT 480

class Instructions
{
public:
	Instructions();
	~Instructions();

	void init();
	void update(int deltaTime);
	void render();

private:
	void initShaders();

private:
	ShaderProgram texProgram;
	glm::mat4 projection;
	Texture instructionsImage;
	TexturedQuad* instructionsQuad;

	float currentTime;


};

#endif