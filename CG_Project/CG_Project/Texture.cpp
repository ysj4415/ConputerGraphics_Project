#include "Texture.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
Texture::Texture() 
{
	VAO = 0; VBO = 0;
	width = 2; height = 2;
	texture = 0;
}
Texture::~Texture() {}

void Texture::initBuffer() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); //--- ��ġ �Ӽ�
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float))); //--- �븻�� �Ӽ�
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); //--- �ؽ�ó ��ǥ �Ӽ�
	glEnableVertexAttribArray(2);
}
void Texture::InitTexture(const char* c)
{
	int widthImage, heightImage, numberOfChannel;
	BITMAP* bmp;

	glGenTextures(1, &texture); //--- �ؽ�ó ����
	glBindTexture(GL_TEXTURE_2D, texture); //--- �ؽ�ó ���ε�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //--- ���� ���ε��� �ؽ�ó�� �Ķ���� �����ϱ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(c, &widthImage, &heightImage, &numberOfChannel, 0);
	//unsigned char* data = LoadDIBitmap("texture.bmp", &bmp); //--- �ؽ�ó�� ����� ��Ʈ�� �̹��� �ε��ϱ�
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data); //---�ؽ�ó �̹��� ����
	stbi_image_free(data);
}
void Texture::Draw()
{
	glUseProgram(Ts_program);

	unsigned int modelLoc = glGetUniformLocation(Ts_program, "model");
	glm::mat4 TR = transform.GetMat();


	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(TR));
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}
GLubyte* Texture::LoadDIBitmap(const char* filename, BITMAPINFO** info)
{
	FILE* fp;
	GLubyte* bits;
	int bitsize, infosize;
	BITMAPFILEHEADER header;
	//--- ���̳ʸ� �б� ���� ������ ����
	if ((fp = fopen(filename, "rb")) == NULL)
		return NULL;
	//--- ��Ʈ�� ���� ����� �д´�.
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1) {
		fclose(fp); return NULL;
	}
	//--- ������ BMP �������� Ȯ���Ѵ�.
	if (header.bfType != 'MB') {
		fclose(fp); return NULL;
	}
	//--- BITMAPINFOHEADER ��ġ�� ����.
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	//--- ��Ʈ�� �̹��� �����͸� ���� �޸� �Ҵ��� �Ѵ�.
	if ((*info = (BITMAPINFO*)malloc(infosize)) == NULL) {
		fclose(fp); return NULL;
	}
		//--- ��Ʈ�� ���� ����� �д´�.
		if (fread(*info, 1, infosize, fp) < (unsigned int)infosize) {
			free(*info);
			fclose(fp); return NULL;
		}
	//--- ��Ʈ���� ũ�� ����
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth *
			(*info)->bmiHeader.biBitCount + 7) / 8.0 *
		abs((*info)->bmiHeader.biHeight);
	//--- ��Ʈ���� ũ�⸸ŭ �޸𸮸� �Ҵ��Ѵ�.
	if ((bits = (unsigned char*)malloc(bitsize)) == NULL) {
		free(*info);
		fclose(fp); return NULL;
	}
	//--- ��Ʈ�� �����͸� bit(GLubyte Ÿ��)�� �����Ѵ�.
	if (fread(bits, 1, bitsize, fp) < (unsigned int)bitsize) {
		free(*info); free(bits);
		fclose(fp); return NULL;
	}
	fclose(fp);
	return bits;
}