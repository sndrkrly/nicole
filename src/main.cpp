#include <iostream>
#include "base/renderer/Window.h"

int main( int argc, char *argv[] )
{
    std::cout << "We are all alone on life's journey, held captive by the limitations of human consciousness.\n" << std::endl;

    CWindow* m_pWindow = new CWindow( );
    m_pWindow->Create( "Nicole", 640, 480 );

    return 0;
}
