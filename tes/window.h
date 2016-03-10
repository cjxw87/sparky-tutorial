//
//  window.h
//  tes
//
//  Created by xiaoweiwu on 1/16/16.
//  Copyright © 2016 xiaoweiwu. All rights reserved.
//

#pragma once
#include <GL/glew.h>
#include <iostream>
#include <GLFW/glfw3.h>

namespace sparky{
    namespace graphics{
        

#define MAX_KEYS 1024
#define MAX_BUTTONS 32
        

    class Window{
              private:
            const char *m_Name;
            int m_width,m_height;
            GLFWwindow *m_Window;
            bool m_closed;
             double mx,my;
            
        public:
        static Window *INSTANCE;

          bool m_MouseButtons[MAX_BUTTONS];
        
        bool m_Keys[MAX_KEYS];

            Window(char *name,int width,int height);
            ~Window();
            void update();
            bool closed() const;
            void clear() const;
            inline int getWidth(){return m_width;}
            inline int getHeight(){return m_height;}
        bool isKeyPressed(int keyCode);
        bool isMouseButtonPressed(int button);
        void getMousePosition(double& x,double& y);
        
        private:
            bool init();
        static  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouse_button_callback(GLFWwindow *window,int button,int action,int mods);
        static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        };
    }
    

}



