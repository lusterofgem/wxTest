#include <iostream>
#include <chrono>
#include <thread>

#include <GL/glew.h>
#include <GL/glut.h>
#include <wx/dcclient.h>
#include <wx/event.h>

#include "GLCanvas.h"

// void GLCanvas::OnPaint(wxPaintEvent& event)
// {
//     std::cout << "GLCanvas::OnPaint()\n";
// }

BEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
    EVT_PAINT(GLCanvas::paint)
END_EVENT_TABLE()

void GLCanvas::paint(wxPaintEvent &event)
{
    // This is required even though dc is not used otherwise.
    wxPaintDC dc(this);

    // Set the OpenGL viewport according to the client size of this canvas.
    // This is done here rather than in a wxSizeEvent handler because our
    // OpenGL rendering context (and thus viewport setting) is used with
    // multiple canvases: If we updated the viewport in the wxSizeEvent
    // handler, changing the size of one canvas causes a viewport setting that
    // is wrong when next another canvas is repainted.
    const wxSize ClientSize = GetClientSize();

    // TestGLContext& canvas = wxGetApp().GetContext(this, m_useStereo);
    glViewport(0, 0, ClientSize.x, ClientSize.y);

    // Render the graphics and swap the buffers.
    GLboolean quadStereoSupported;
    glGetBooleanv( GL_STEREO, &quadStereoSupported);
    if ( quadStereoSupported )
    {
        glDrawBuffer( GL_BACK_LEFT );
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-0.47f, 0.53f, -0.5f, 0.5f, 1.0f, 3.0f);
        // canvas.DrawRotatedCube(m_xangle, m_yangle);
        // CheckGLError();
        glDrawBuffer( GL_BACK_RIGHT );
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-0.53f, 0.47f, -0.5f, 0.5f, 1.0f, 3.0f);
        // canvas.DrawRotatedCube(m_xangle, m_yangle);
        // CheckGLError();
    }
    else
    {
        // canvas.DrawRotatedCube(m_xangle, m_yangle);
        // if ( m_useStereo && !m_stereoWarningAlreadyDisplayed )
        // {
            // m_stereoWarningAlreadyDisplayed = true;
            wxLogError("Stereo not supported by the graphics card.");
        // }
    }
    SwapBuffers();
}

GLCanvas::GLCanvas(wxWindow *parent)
:wxGLCanvas(parent, wxID_ANY, nullptr)
{
    // auto err = glewInit();
    // if (err != GLEW_OK) {
    //     fprintf(stderr, "Failed to initialize GLEW\n");
    //     std::cout << glewGetErrorString(err) << "\n";
    //     throw std::exception();


    // GLuint VertexArrayID;
    // glGenVertexArrays(1, &VertexArrayID);
    // glBindVertexArray(VertexArrayID);

    // static const GLfloat vertex[] = {
    //     1.0f, 0.0f, 0.0f,
    //     -1.0f, 0.0f, 0.0f,
    //     0.0f, 1.0f, 0.0f,
    // };

    // GLuint vertexBuffer;
    // glGenBuffers(1, &vertexBuffer);
    // glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
    //
    // glEnableVertexAttribArray(0);
    // glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    // glVertexAttribPointer(
    //    0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
    //    3,                  // size
    //    GL_FLOAT,           // type
    //    GL_FALSE,           // normalized?
    //    0,                  // stride
    //    (void*)0            // array buffer offset
    // );
    // // Draw the triangle !
    // glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    // glDisableVertexAttribArray(0);
}
