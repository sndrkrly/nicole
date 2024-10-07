#include "Game.h"

void CGame::PreLoop( )
{
	m_pGLRenderer->HotloadTestShader( );
}

void CGame::Loop( )
{   
	m_pGLRenderer->DrawTestShader( );
}

void CGame::UpdateLoop( int fDeltaTime )
{
    std::cout << fDeltaTime << std::endl;
}

void CGame::StopLoop( )
{
	m_pGLRenderer->HotdestroyTestShader( );
}
