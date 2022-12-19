#include "Ball.h"
#include "ShaderProgram.h"
#include "GameWorld.h"
Ball::Ball() :Actor()
{
	speed = -3.0f;
	life = 0.0f;

	tilecount = 0;

	main_ball.SetColor(1.0, 0.0, 0.0);
	sub_ball.SetColor(0.0, 0.0, 1.0);

	main_ball.transform.SetScale(0.05, 0.05, 0.05);
	sub_ball.transform.SetScale(0.05, 0.05, 0.05);
	sub_ball.transform.SetTrans(-2.0, 0.0, 0.0);

	sub_ball_guideline.transform.SetScale(0.0, 0.0, 0.0);

	transform.SetTrans(0.0, 0.6, 0.0);
}
Ball::~Ball() {}

void Ball::Draw(glm::mat4 view, glm::mat4 projection)
{
	glUseProgram(s_program);

	unsigned int viewLoc = glGetUniformLocation(s_program, "view"); //--- 뷰잉 변환 설정
	unsigned int projLoc = glGetUniformLocation(s_program, "projection");
	unsigned int modelLoc = glGetUniformLocation(s_program, "model");
	int vColorLocation = glGetUniformLocation(s_program, "vColor");

	glm::mat4 ObjectTR = transform.GetMat();
	glm::mat4 MeshTR = main_ball.transform.GetMat();
	glm::mat4 TR = ObjectTR * MeshTR;


	glBindVertexArray(main_ball.vao);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(TR));
	glUniform3f(vColorLocation, main_ball.GetColor().x, main_ball.GetColor().y, main_ball.GetColor().z);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projection[0][0]);

	glDrawElements(GL_TRIANGLES, main_ball.GetfaceNum() * 3, GL_UNSIGNED_INT, (GLvoid*)(sizeof(GLuint) * 0));



	MeshTR = sub_ball.transform.GetMat();
	TR = ObjectTR * MeshTR;

	glBindVertexArray(sub_ball.vao);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(TR));
	glUniform3f(vColorLocation, sub_ball.GetColor().x, sub_ball.GetColor().y, sub_ball.GetColor().z);

	glDrawElements(GL_TRIANGLES, sub_ball.GetfaceNum() * 3, GL_UNSIGNED_INT, (GLvoid*)(sizeof(GLuint) * 0));

	
	//-----------------------------------------------
	//가이드 라인1
	MeshTR = main_ball_guideline.transform.GetMat();

	glBindVertexArray(main_ball_guideline.vao);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(MeshTR));
	glUniform3f(vColorLocation, main_ball.GetColor().x, main_ball.GetColor().y, main_ball.GetColor().z);
	glPointSize(1.5);
	glDrawArrays(GL_POINTS, 0, main_ball_guideline.GetVertexNum());

	//가이드 라인2
	MeshTR = sub_ball_guideline.transform.GetMat();

	glBindVertexArray(sub_ball_guideline.vao);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(MeshTR));
	glUniform3f(vColorLocation, sub_ball.GetColor().x, sub_ball.GetColor().y, sub_ball.GetColor().z);
	glPointSize(1.5);
	glDrawArrays(GL_POINTS, 0, sub_ball_guideline.GetVertexNum());
}
glm::vec4 Ball::GetSubBallLoc()
{
	glm::vec4 SubBallLoc = glm::vec4(0.0, 0.0, 0.0, 1.0);
	glm::mat4 TR = transform.GetMat() * sub_ball.transform.GetMat();
	SubBallLoc = TR * SubBallLoc;
	return SubBallLoc;
}

void Ball::ChangeBalls(GLfloat x, GLfloat z)
{
	//공의 색 바꾸기
	glm::vec3 temp = main_ball.GetColor();
	main_ball.SetColor(sub_ball.GetColor().x, sub_ball.GetColor().y, sub_ball.GetColor().z);
	sub_ball.SetColor(temp.x, temp.y, temp.z);

	//ball 오브젝트 위치 변경
	glm::vec4 SubBallLoc = GetSubBallLoc();
	transform.SetTrans(x, SubBallLoc.y, z);

	//sub ball 위치 바꾸기
	transform.Add_Rotate(0.0, 180.0, 0.0);

	//가이드 라인 설정
	main_ball_guideline.transform.SetScale(0.0, 0.0, 0.0);
	sub_ball_guideline.transform.SetScale(0.7, 0.7, 0.7);

	//---라이프 초기화
	life = 0;

	tilecount++;
	std::cout << tilecount << std::endl;
}
void Ball::InitBuffer()
{
	main_ball.InitBuffer("sphere.obj");
	sub_ball.InitBuffer("sphere.obj");
	main_ball_guideline.InitBuffer(40, 2.0);
	sub_ball_guideline.InitBuffer(40, 2.0);
}

void Ball::Update()
{
	if (starttimer < 100)
	{
		starttimer++;
	}
	else
	{
		transform.Add_Rotate(0.0, speed, 0.0);
		life += speed * -1;


		//---게임 오버 체크
		if (life >= 360)
		{
			if (sub_ball.transform.GetTrans().x < 0.0)
				sub_ball.transform.Add_Trans(0.03, 0.0, 0.0);
			else
				sub_ball.transform.SetScale(0.0, 0.0, 0.0);

			if (endtimer > 100)
			{
				MainState* mainstate = new MainState;
				cur_state->next_state = mainstate;
			}
			else
			{
				endtimer++;
			}
		}
		else
		{
			//---가이드라인 위치 설정
			main_ball_guideline.transform.SetTrans(transform.GetTrans().x, transform.GetTrans().y, transform.GetTrans().z);
			glm::vec4 SubBallLoc = GetSubBallLoc();
			sub_ball_guideline.transform.SetTrans(SubBallLoc.x, SubBallLoc.y, SubBallLoc.z);

			//---가이드라인 크기 설정
			if (main_ball_guideline.transform.GetScale().x < 1.0)
			{
				main_ball_guideline.transform.Add_Scale(0.1, 0.1, 0.1);
			}
			if (sub_ball_guideline.transform.GetScale().y > 0.0)
			{
				sub_ball_guideline.transform.Add_Scale(-0.1, -0.1, -0.1);
			}
		}
	}
}