//
//  window.cpp
//  tes
//
//  Created by xiaoweiwu on 1/16/16.
//  Copyright © 2016 xiaoweiwu. All rights reserved.
//

#include <stdio.h>
#include "window.h"

namespace sparky {
    namespace graphics{
        
        Window *Window::INSTANCE;
        
        
        void window_resize(GLFWwindow *window,int width,int height);
//        void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

        
        Window::Window(char *name,int width,int height){
            m_Name=name;
            m_width=width;
            m_height=height;
            if (!init()) {
                glfwTerminate();
            }
            
            for (int i=0; i<MAX_KEYS; i++) {
                m_Keys[i]=false;
            }
            
            for (int i=0; i<MAX_BUTTONS; i++) {
                m_MouseButtons[i]=false;
            }
            INSTANCE=this;
        }
        
        Window::~Window(){
            glfwTerminate();
            
        }
        
        bool Window::init(){
            
            if (!glfwInit()) {
                std::cout<<"failed to initalize glfw"<<std::endl;
                return false;
            }
            
            m_Window=glfwCreateWindow(m_width, m_height, m_Name, NULL, NULL);
            if (!m_Window) {
                std::cout<<"failed to create glfw window"<<std::endl;
                return false;
            }
            glfwMakeContextCurrent(m_Window);
            glfwSetWindowUserPointer(m_Window, this);
            glfwSetFramebufferSizeCallback(m_Window, window_resize);
            glfwSetKeyCallback(m_Window,key_callback);
            glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
            glfwSetCursorPosCallback(m_Window, cursor_position_callback);
            
            glewExperimental=GL_TRUE;
            if (glewInit()!=GLEW_OK) {
                std::cout<<"can not initialize glew!"<<std::endl;
                
                return false;
            }
            
            std::cout<<"Opengl version"<<glGetString(GL_VERSION)<<std::endl;
        
            return true;
        }
        
        bool Window::closed() const{
            return  glfwWindowShouldClose(m_Window)==1;
        }
        
        void Window::update(){
            glfwPollEvents();
            glfwGetFramebufferSize(m_Window, &m_width, &m_height);
//            glViewport(0, 0, m_width, m_height);
            glfwSwapBuffers(m_Window);
            
        }
        
        void Window::clear() const{
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            
        }
        
        
        void window_resize(GLFWwindow *window,int width,int height){
            glViewport(0, 0, width, height);
        }
        
        bool Window::isKeyPressed(int keyCode){
            if (keyCode>MAX_KEYS) {
                return false;
            }
            
            return m_Keys[keyCode];
        }
        
        
        bool Window::isMouseButtonPressed(int button){
            if (button>MAX_BUTTONS) {
                return false;
            }
            
            return m_MouseButtons[button];
            
        }
        
        
        void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
            Window *win=(Window *)glfwGetWindowUserPointer(window);
            win->m_Keys[key]=action!=GLFW_RELEASE;
        }
        
        void Window::mouse_button_callback(GLFWwindow *window, int button, int action, int mods){
            Window *win=(Window *)glfwGetWindowUserPointer(window);
            win->m_MouseButtons[button]=action!=GLFW_RELEASE;
            
        }
        
        void Window::getMousePosition(double &x, double &y){
            x=mx;
            y=my;
        }
        
        
        void Window::cursor_position_callback(GLFWwindow *window, double xpos, double ypos){
            Window *win=(Window *)glfwGetWindowUserPointer(window);
            win->mx=xpos;
            win->my=ypos;
        }
        
    }
}