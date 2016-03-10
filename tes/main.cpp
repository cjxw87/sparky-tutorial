//
//  main.cpp
//  tes
//
//  Created by xiaoweiwu on 1/16/16.
//  Copyright © 2016 xiaoweiwu. All rights reserved.
//

#include "window.h"
#include <iostream>
#include "vec2.h"
#include "maths.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    using namespace sparky;
    using namespace graphics;
    using namespace maths;
    Window window("Sparky",800,600);
    glClearColor(0.2f,0.3f, 0.8f, 1.0f);
    std::cout<<glGetString(GL_VERSION)<<std::endl;
    
    
    GLuint vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    
    vec2 vector(1.0f,2.0f);
    
    mat4 translation=mat4::translation(vec3(0,2,3));
    
    while (!window.closed()) {
//        glClear(GL_COLOR_BUFFER_BIT);
//        if (Window::isMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
//            std::cout<<"Pressed!"<<std::endl;
//        }
        
        double x,y;
        window.getMousePosition(x, y);
        std::cout<<x<<","<<y<<std::endl;
    
        
        
        window.clear();
//        glBegin(GL_TRIANGLES);
//        glVertex2f(-0.5f, -0.5f);
//        glVertex2f(0, 0.5f);
//        glVertex2f(0.5f, -0.5f);
//
//        glEnd();
        
        
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
    
        window.update();
    }
    
//    std::cin.get();
    return 0;
}
