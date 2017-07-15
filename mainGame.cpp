#include "stdafx.h"
#include "mainGame.h"

//======================================
// 생성자랑 소멸자는 쓰지 않는다
//======================================
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}


//======================================
// 생성자랑 소멸자는 쓰지 않는다
//======================================


//초기화는 앞으로 여기에다가 해라
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	SCENEMANAGER->addScene("SCENE_OPENEING", new openingScene);
	SCENEMANAGER->addScene("SCENE_WORLDMAP", new worldMapScene);

	SCENEMANAGER->changeScene("SCENE_OPENEING");

	return S_OK;
}

//메모리 해제는 앞으로 여기에다가 해라
void mainGame::release(void)
{
	gameNode::release();

}

//연산은(는) 앞으로 여기에다가 해라
void mainGame::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
}

//앞으로 여기에다 그려라 
void mainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ 위에 건들지마라 ================

	SCENEMANAGER->render();

	//TIMEMANAGER->render(getMemDC());

	//===============아래도 건들지마라 =================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
