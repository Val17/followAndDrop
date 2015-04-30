#include "arm.h"

Arm::Arm()
{

}

void Arm::drawArm()
{

    qDebug()<<"Arm";

    /*glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glEnable ( GL_NORMALIZE );
    glDepthMask ( GL_TRUE );
    glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
    glPointSize ( 1.0f );
    glLineWidth ( 1.0f );
    glEnable(GL_COLOR_MATERIAL);*/

    glColor3f(1,0,0);

    glPushMatrix ();

        glScalef(3,3,0.5);

    glPopMatrix ();

    glPushMatrix ();

        glTranslatef(0,0,1.5);
        glRotatef(30,0,1,0);

        glPushMatrix ();

            glPushMatrix ();

                glScalef(2,2,2);
                glColor3f(0,0,1);

            glPopMatrix ();

            glPushMatrix ();

                GLUquadric* params = gluNewQuadric();
                gluSphere(params,0.75,20,20);

            glPopMatrix ();

            glPushMatrix ();

                glTranslatef(0,0,3);
                glScalef(1,1,3);
                glColor3f(0,1,0);

                glBegin ( GL_QUADS );

                    glNormal3f(-0.57735,-0.57735,-0.57735);
                    glVertex3f(-0.5,-0.5,-0.5);
                    glNormal3f(-0.57735,-0.57735,0.57735);
                    glVertex3f(-0.5,-0.5,0.5);
                    glNormal3f(-0.57735,0.57735,0.57735);
                    glVertex3f(-0.5,0.5,0.5);
                    glNormal3f(-0.57735,0.57735,-0.57735);
                    glVertex3f(-0.5,0.5,-0.5);
                    glNormal3f(-0.57735,-0.57735,0.57735);
                    glVertex3f(-0.5,-0.5,0.5);
                    glNormal3f(0.57735,-0.57735,0.57735);
                    glVertex3f(0.5,-0.5,0.5);
                    glNormal3f(0.57735,0.57735,0.57735);
                    glVertex3f(0.5,0.5,0.5);
                    glNormal3f(-0.57735,0.57735,0.57735);
                    glVertex3f(-0.5,0.5,0.5);
                    glNormal3f(0.57735,-0.57735,0.57735);
                    glVertex3f(0.5,-0.5,0.5);
                    glNormal3f(0.57735,-0.57735,-0.57735);
                    glVertex3f(0.5,-0.5,-0.5);
                    glNormal3f(0.57735,0.57735,-0.57735);
                    glVertex3f(0.5,0.5,-0.5);
                    glNormal3f(0.57735,0.57735,0.57735);
                    glVertex3f(0.5,0.5,0.5);
                    glNormal3f(0.57735,-0.57735,-0.57735);
                    glVertex3f(0.5,-0.5,-0.5);
                    glNormal3f(-0.57735,-0.57735,-0.57735);
                    glVertex3f(-0.5,-0.5,-0.5);
                    glNormal3f(-0.57735,0.57735,-0.57735);
                    glVertex3f(-0.5,0.5,-0.5);
                    glNormal3f(0.57735,0.57735,-0.57735);
                    glVertex3f(0.5,0.5,-0.5);
                    glNormal3f(-0.57735,0.57735,0.57735);
                    glVertex3f(-0.5,0.5,0.5);
                    glNormal3f(0.57735,0.57735,0.57735);
                    glVertex3f(0.5,0.5,0.5);
                    glNormal3f(0.57735,0.57735,-0.57735);
                    glVertex3f(0.5,0.5,-0.5);
                    glNormal3f(-0.57735,0.57735,-0.57735);
                    glVertex3f(-0.5,0.5,-0.5);
                    glNormal3f(-0.57735,-0.57735,-0.57735);
                    glVertex3f(-0.5,-0.5,-0.5);
                    glNormal3f(0.57735,-0.57735,-0.57735);
                    glVertex3f(0.5,-0.5,-0.5);
                    glNormal3f(0.57735,-0.57735,0.57735);
                    glVertex3f(0.5,-0.5,0.5);
                    glNormal3f(-0.57735,-0.57735,0.57735);
                    glVertex3f(-0.5,-0.5,0.5);

                glEnd ();

            glPopMatrix ();

            glPushMatrix ();

                GLUquadric* params2 = gluNewQuadric();
                gluSphere(params2,0.75,20,20);

            glPopMatrix ();

            glPushMatrix ();

                glTranslatef(0,0,5.5);
                glRotatef(40,1,0,0);

                glPushMatrix ();

                    glPushMatrix ();

                        glScalef(1.5,1.5,1.5);
                        glColor3f(1,0,0);

                    glPopMatrix ();

                    glPushMatrix ();

                        glTranslatef(0,0,2.5);
                        glScalef(1,1,3);
                        glColor3f(1,1,0);

                        glBegin ( GL_QUADS );

                            glNormal3f(-0.57735,-0.57735,-0.57735);
                            glVertex3f(-0.5,-0.5,-0.5);
                            glNormal3f(-0.57735,-0.57735,0.57735);
                            glVertex3f(-0.5,-0.5,0.5);
                            glNormal3f(-0.57735,0.57735,0.57735);
                            glVertex3f(-0.5,0.5,0.5);
                            glNormal3f(-0.57735,0.57735,-0.57735);
                            glVertex3f(-0.5,0.5,-0.5);
                            glNormal3f(-0.57735,-0.57735,0.57735);
                            glVertex3f(-0.5,-0.5,0.5);
                            glNormal3f(0.57735,-0.57735,0.57735);
                            glVertex3f(0.5,-0.5,0.5);
                            glNormal3f(0.57735,0.57735,0.57735);
                            glVertex3f(0.5,0.5,0.5);
                            glNormal3f(-0.57735,0.57735,0.57735);
                            glVertex3f(-0.5,0.5,0.5);
                            glNormal3f(0.57735,-0.57735,0.57735);
                            glVertex3f(0.5,-0.5,0.5);
                            glNormal3f(0.57735,-0.57735,-0.57735);
                            glVertex3f(0.5,-0.5,-0.5);
                            glNormal3f(0.57735,0.57735,-0.57735);
                            glVertex3f(0.5,0.5,-0.5);
                            glNormal3f(0.57735,0.57735,0.57735);
                            glVertex3f(0.5,0.5,0.5);
                            glNormal3f(0.57735,-0.57735,-0.57735);
                            glVertex3f(0.5,-0.5,-0.5);
                            glNormal3f(-0.57735,-0.57735,-0.57735);
                            glVertex3f(-0.5,-0.5,-0.5);
                            glNormal3f(-0.57735,0.57735,-0.57735);
                            glVertex3f(-0.5,0.5,-0.5);
                            glNormal3f(0.57735,0.57735,-0.57735);
                            glVertex3f(0.5,0.5,-0.5);
                            glNormal3f(-0.57735,0.57735,0.57735);
                            glVertex3f(-0.5,0.5,0.5);
                            glNormal3f(0.57735,0.57735,0.57735);
                            glVertex3f(0.5,0.5,0.5);
                            glNormal3f(0.57735,0.57735,-0.57735);
                            glVertex3f(0.5,0.5,-0.5);
                            glNormal3f(-0.57735,0.57735,-0.57735);
                            glVertex3f(-0.5,0.5,-0.5);
                            glNormal3f(-0.57735,-0.57735,-0.57735);
                            glVertex3f(-0.5,-0.5,-0.5);
                            glNormal3f(0.57735,-0.57735,-0.57735);
                            glVertex3f(0.5,-0.5,-0.5);
                            glNormal3f(0.57735,-0.57735,0.57735);
                            glVertex3f(0.5,-0.5,0.5);
                            glNormal3f(-0.57735,-0.57735,0.57735);
                            glVertex3f(-0.5,-0.5,0.5);

                        glEnd ();

                    glPopMatrix ();


                    glPushMatrix ();

                        glTranslatef(0,0,5.5);
                        glRotatef(30,1,0,0);

                        glPushMatrix ();

                            glPushMatrix ();
                            glScalef(2,2,2);
                            glColor3f(1,0,1);

                        glPopMatrix ();

                        glPushMatrix ();

                            glTranslatef(0,-2,3.5);
                            glRotatef(30,1,0,0);
                            glScalef(1,1,5);
                            glColor3f(0,1,1);

                            glBegin ( GL_TRIANGLES );

                                glNormal3f(0.689152,6.47858e-008,-0.724617);
                                glVertex3f(0.5,0,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.557535,0.405073,-0.724617);
                                glVertex3f(0.404509,0.293893,-0.5);
                                glNormal3f(0.557535,0.405073,-0.724617);
                                glVertex3f(0.404509,0.293893,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.21296,0.655422,-0.724617);
                                glVertex3f(0.154508,0.475528,-0.5);
                                glNormal3f(0.21296,0.655422,-0.724617);
                                glVertex3f(0.154508,0.475528,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.21296,0.655422,-0.724617);
                                glVertex3f(-0.154509,0.475528,-0.5);
                                glNormal3f(-0.21296,0.655422,-0.724617);
                                glVertex3f(-0.154509,0.475528,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.557536,0.405073,-0.724617);
                                glVertex3f(-0.404509,0.293893,-0.5);
                                glNormal3f(-0.557536,0.405073,-0.724617);
                                glVertex3f(-0.404509,0.293893,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.689152,-4.31905e-008,-0.724617);
                                glVertex3f(-0.5,-4.37114e-008,-0.5);
                                glNormal3f(-0.689152,-4.31905e-008,-0.724617);
                                glVertex3f(-0.5,-4.37114e-008,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.557535,-0.405073,-0.724617);
                                glVertex3f(-0.404508,-0.293893,-0.5);
                                glNormal3f(-0.557535,-0.405073,-0.724617);
                                glVertex3f(-0.404508,-0.293893,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.21296,-0.655422,-0.724617);
                                glVertex3f(-0.154509,-0.475528,-0.5);
                                glNormal3f(-0.21296,-0.655422,-0.724617);
                                glVertex3f(-0.154509,-0.475528,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.21296,-0.655422,-0.724617);
                                glVertex3f(0.154509,-0.475528,-0.5);
                                glNormal3f(0.21296,-0.655422,-0.724617);
                                glVertex3f(0.154509,-0.475528,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.557536,-0.405073,-0.724617);
                                glVertex3f(0.404509,-0.293892,-0.5);
                                glNormal3f(0.557536,-0.405073,-0.724617);
                                glVertex3f(0.404509,-0.293892,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.689152,6.47858e-008,-0.724617);
                                glVertex3f(0.5,0,-0.5);
                                glNormal3f(0.557535,0.405073,0.724617);
                                glVertex3f(0.404509,0.293893,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.689152,6.47858e-008,0.724617);
                                glVertex3f(0.5,0,0.5);
                                glNormal3f(0.21296,0.655422,0.724617);
                                glVertex3f(0.154508,0.475528,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.557535,0.405073,0.724617);
                                glVertex3f(0.404509,0.293893,0.5);
                                glNormal3f(-0.21296,0.655422,0.724617);
                                glVertex3f(-0.154509,0.475528,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.21296,0.655422,0.724617);
                                glVertex3f(0.154508,0.475528,0.5);
                                glNormal3f(-0.557536,0.405073,0.724617);
                                glVertex3f(-0.404509,0.293893,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.21296,0.655422,0.724617);
                                glVertex3f(-0.154509,0.475528,0.5);
                                glNormal3f(-0.689152,-4.31905e-008,0.724617);
                                glVertex3f(-0.5,-4.37114e-008,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.557536,0.405073,0.724617);
                                glVertex3f(-0.404509,0.293893,0.5);
                                glNormal3f(-0.557535,-0.405073,0.724617);
                                glVertex3f(-0.404508,-0.293893,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.689152,-4.31905e-008,0.724617);
                                glVertex3f(-0.5,-4.37114e-008,0.5);
                                glNormal3f(-0.21296,-0.655422,0.724617);
                                glVertex3f(-0.154509,-0.475528,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.557535,-0.405073,0.724617);
                                glVertex3f(-0.404508,-0.293893,0.5);
                                glNormal3f(0.21296,-0.655422,0.724617);
                                glVertex3f(0.154509,-0.475528,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.21296,-0.655422,0.724617);
                                glVertex3f(-0.154509,-0.475528,0.5);
                                glNormal3f(0.557536,-0.405073,0.724617);
                                glVertex3f(0.404509,-0.293892,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.21296,-0.655422,0.724617);
                                glVertex3f(0.154509,-0.475528,0.5);
                                glNormal3f(0.689152,6.47858e-008,0.724617);
                                glVertex3f(0.5,0,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.557536,-0.405073,0.724617);
                                glVertex3f(0.404509,-0.293892,0.5);


                            glEnd ();

                            glBegin ( GL_QUADS );

                                glNormal3f(0.689152,6.47858e-008,-0.724617);
                                glVertex3f(0.5,0,-0.5);
                                glNormal3f(0.557535,0.405073,-0.724617);
                                glVertex3f(0.404509,0.293893,-0.5);
                                glNormal3f(0.557535,0.405073,0.724617);
                                glVertex3f(0.404509,0.293893,0.5);
                                glNormal3f(0.689152,6.47858e-008,0.724617);
                                glVertex3f(0.5,0,0.5);
                                glNormal3f(0.557535,0.405073,-0.724617);
                                glVertex3f(0.404509,0.293893,-0.5);
                                glNormal3f(0.21296,0.655422,-0.724617);
                                glVertex3f(0.154508,0.475528,-0.5);
                                glNormal3f(0.21296,0.655422,0.724617);
                                glVertex3f(0.154508,0.475528,0.5);
                                glNormal3f(0.557535,0.405073,0.724617);
                                glVertex3f(0.404509,0.293893,0.5);
                                glNormal3f(0.21296,0.655422,-0.724617);
                                glVertex3f(0.154508,0.475528,-0.5);
                                glNormal3f(-0.21296,0.655422,-0.724617);
                                glVertex3f(-0.154509,0.475528,-0.5);
                                glNormal3f(-0.21296,0.655422,0.724617);
                                glVertex3f(-0.154509,0.475528,0.5);
                                glNormal3f(0.21296,0.655422,0.724617);
                                glVertex3f(0.154508,0.475528,0.5);
                                glNormal3f(-0.21296,0.655422,-0.724617);
                                glVertex3f(-0.154509,0.475528,-0.5);
                                glNormal3f(-0.557536,0.405073,-0.724617);
                                glVertex3f(-0.404509,0.293893,-0.5);
                                glNormal3f(-0.557536,0.405073,0.724617);
                                glVertex3f(-0.404509,0.293893,0.5);
                                glNormal3f(-0.21296,0.655422,0.724617);
                                glVertex3f(-0.154509,0.475528,0.5);
                                glNormal3f(-0.557536,0.405073,-0.724617);
                                glVertex3f(-0.404509,0.293893,-0.5);
                                glNormal3f(-0.689152,-4.31905e-008,-0.724617);
                                glVertex3f(-0.5,-4.37114e-008,-0.5);
                                glNormal3f(-0.689152,-4.31905e-008,0.724617);
                                glVertex3f(-0.5,-4.37114e-008,0.5);
                                glNormal3f(-0.557536,0.405073,0.724617);
                                glVertex3f(-0.404509,0.293893,0.5);
                                glNormal3f(-0.689152,-4.31905e-008,-0.724617);
                                glVertex3f(-0.5,-4.37114e-008,-0.5);
                                glNormal3f(-0.557535,-0.405073,-0.724617);
                                glVertex3f(-0.404508,-0.293893,-0.5);
                                glNormal3f(-0.557535,-0.405073,0.724617);
                                glVertex3f(-0.404508,-0.293893,0.5);
                                glNormal3f(-0.689152,-4.31905e-008,0.724617);
                                glVertex3f(-0.5,-4.37114e-008,0.5);
                                glNormal3f(-0.557535,-0.405073,-0.724617);
                                glVertex3f(-0.404508,-0.293893,-0.5);
                                glNormal3f(-0.21296,-0.655422,-0.724617);
                                glVertex3f(-0.154509,-0.475528,-0.5);
                                glNormal3f(-0.21296,-0.655422,0.724617);
                                glVertex3f(-0.154509,-0.475528,0.5);
                                glNormal3f(-0.557535,-0.405073,0.724617);
                                glVertex3f(-0.404508,-0.293893,0.5);
                                glNormal3f(-0.21296,-0.655422,-0.724617);
                                glVertex3f(-0.154509,-0.475528,-0.5);
                                glNormal3f(0.21296,-0.655422,-0.724617);
                                glVertex3f(0.154509,-0.475528,-0.5);
                                glNormal3f(0.21296,-0.655422,0.724617);
                                glVertex3f(0.154509,-0.475528,0.5);
                                glNormal3f(-0.21296,-0.655422,0.724617);
                                glVertex3f(-0.154509,-0.475528,0.5);
                                glNormal3f(0.21296,-0.655422,-0.724617);
                                glVertex3f(0.154509,-0.475528,-0.5);
                                glNormal3f(0.557536,-0.405073,-0.724617);
                                glVertex3f(0.404509,-0.293892,-0.5);
                                glNormal3f(0.557536,-0.405073,0.724617);
                                glVertex3f(0.404509,-0.293892,0.5);
                                glNormal3f(0.21296,-0.655422,0.724617);
                                glVertex3f(0.154509,-0.475528,0.5);
                                glNormal3f(0.557536,-0.405073,-0.724617);
                                glVertex3f(0.404509,-0.293892,-0.5);
                                glNormal3f(0.689152,6.47858e-008,-0.724617);
                                glVertex3f(0.5,0,-0.5);
                                glNormal3f(0.689152,6.47858e-008,0.724617);
                                glVertex3f(0.5,0,0.5);
                                glNormal3f(0.557536,-0.405073,0.724617);
                                glVertex3f(0.404509,-0.293892,0.5);

                            glEnd ();

                        glPopMatrix ();

                        glPushMatrix ();

                        GLUquadric* params3 = gluNewQuadric();
                        gluSphere(params3,0.75,20,20);

                        glPopMatrix ();


                        glPushMatrix ();

                            glTranslatef(0,2,3.5);
                            glRotatef(-30,1,0,0);
                            glScalef(1,1,5);

                            glBegin ( GL_TRIANGLES );

                                glNormal3f(0.689152,6.47858e-008,-0.724617);
                                glVertex3f(0.5,0,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.557535,0.405073,-0.724617);
                                glVertex3f(0.404509,0.293893,-0.5);
                                glNormal3f(0.557535,0.405073,-0.724617);
                                glVertex3f(0.404509,0.293893,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.21296,0.655422,-0.724617);
                                glVertex3f(0.154508,0.475528,-0.5);
                                glNormal3f(0.21296,0.655422,-0.724617);
                                glVertex3f(0.154508,0.475528,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.21296,0.655422,-0.724617);
                                glVertex3f(-0.154509,0.475528,-0.5);
                                glNormal3f(-0.21296,0.655422,-0.724617);
                                glVertex3f(-0.154509,0.475528,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.557536,0.405073,-0.724617);
                                glVertex3f(-0.404509,0.293893,-0.5);
                                glNormal3f(-0.557536,0.405073,-0.724617);
                                glVertex3f(-0.404509,0.293893,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.689152,-4.31905e-008,-0.724617);
                                glVertex3f(-0.5,-4.37114e-008,-0.5);
                                glNormal3f(-0.689152,-4.31905e-008,-0.724617);
                                glVertex3f(-0.5,-4.37114e-008,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.557535,-0.405073,-0.724617);
                                glVertex3f(-0.404508,-0.293893,-0.5);
                                glNormal3f(-0.557535,-0.405073,-0.724617);
                                glVertex3f(-0.404508,-0.293893,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(-0.21296,-0.655422,-0.724617);
                                glVertex3f(-0.154509,-0.475528,-0.5);
                                glNormal3f(-0.21296,-0.655422,-0.724617);
                                glVertex3f(-0.154509,-0.475528,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.21296,-0.655422,-0.724617);
                                glVertex3f(0.154509,-0.475528,-0.5);
                                glNormal3f(0.21296,-0.655422,-0.724617);
                                glVertex3f(0.154509,-0.475528,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.557536,-0.405073,-0.724617);
                                glVertex3f(0.404509,-0.293892,-0.5);
                                glNormal3f(0.557536,-0.405073,-0.724617);
                                glVertex3f(0.404509,-0.293892,-0.5);
                                glNormal3f(0,0,-1);
                                glVertex3f(0,0,-0.5);
                                glNormal3f(0.689152,6.47858e-008,-0.724617);
                                glVertex3f(0.5,0,-0.5);
                                glNormal3f(0.557535,0.405073,0.724617);
                                glVertex3f(0.404509,0.293893,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.689152,6.47858e-008,0.724617);
                                glVertex3f(0.5,0,0.5);
                                glNormal3f(0.21296,0.655422,0.724617);
                                glVertex3f(0.154508,0.475528,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.557535,0.405073,0.724617);
                                glVertex3f(0.404509,0.293893,0.5);
                                glNormal3f(-0.21296,0.655422,0.724617);
                                glVertex3f(-0.154509,0.475528,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.21296,0.655422,0.724617);
                                glVertex3f(0.154508,0.475528,0.5);
                                glNormal3f(-0.557536,0.405073,0.724617);
                                glVertex3f(-0.404509,0.293893,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.21296,0.655422,0.724617);
                                glVertex3f(-0.154509,0.475528,0.5);
                                glNormal3f(-0.689152,-4.31905e-008,0.724617);
                                glVertex3f(-0.5,-4.37114e-008,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.557536,0.405073,0.724617);
                                glVertex3f(-0.404509,0.293893,0.5);
                                glNormal3f(-0.557535,-0.405073,0.724617);
                                glVertex3f(-0.404508,-0.293893,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.689152,-4.31905e-008,0.724617);
                                glVertex3f(-0.5,-4.37114e-008,0.5);
                                glNormal3f(-0.21296,-0.655422,0.724617);
                                glVertex3f(-0.154509,-0.475528,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.557535,-0.405073,0.724617);
                                glVertex3f(-0.404508,-0.293893,0.5);
                                glNormal3f(0.21296,-0.655422,0.724617);
                                glVertex3f(0.154509,-0.475528,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(-0.21296,-0.655422,0.724617);
                                glVertex3f(-0.154509,-0.475528,0.5);
                                glNormal3f(0.557536,-0.405073,0.724617);
                                glVertex3f(0.404509,-0.293892,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.21296,-0.655422,0.724617);
                                glVertex3f(0.154509,-0.475528,0.5);
                                glNormal3f(0.689152,6.47858e-008,0.724617);
                                glVertex3f(0.5,0,0.5);
                                glNormal3f(0,0,1);
                                glVertex3f(0,0,0.5);
                                glNormal3f(0.557536,-0.405073,0.724617);
                                glVertex3f(0.404509,-0.293892,0.5);

                            glEnd ();

                            glBegin ( GL_QUADS );

                                glNormal3f(0.689152,6.47858e-008,-0.724617);
                                glVertex3f(0.5,0,-0.5);
                                glNormal3f(0.557535,0.405073,-0.724617);
                                glVertex3f(0.404509,0.293893,-0.5);
                                glNormal3f(0.557535,0.405073,0.724617);
                                glVertex3f(0.404509,0.293893,0.5);
                                glNormal3f(0.689152,6.47858e-008,0.724617);
                                glVertex3f(0.5,0,0.5);
                                glNormal3f(0.557535,0.405073,-0.724617);
                                glVertex3f(0.404509,0.293893,-0.5);
                                glNormal3f(0.21296,0.655422,-0.724617);
                                glVertex3f(0.154508,0.475528,-0.5);
                                glNormal3f(0.21296,0.655422,0.724617);
                                glVertex3f(0.154508,0.475528,0.5);
                                glNormal3f(0.557535,0.405073,0.724617);
                                glVertex3f(0.404509,0.293893,0.5);
                                glNormal3f(0.21296,0.655422,-0.724617);
                                glVertex3f(0.154508,0.475528,-0.5);
                                glNormal3f(-0.21296,0.655422,-0.724617);
                                glVertex3f(-0.154509,0.475528,-0.5);
                                glNormal3f(-0.21296,0.655422,0.724617);
                                glVertex3f(-0.154509,0.475528,0.5);
                                glNormal3f(0.21296,0.655422,0.724617);
                                glVertex3f(0.154508,0.475528,0.5);
                                glNormal3f(-0.21296,0.655422,-0.724617);
                                glVertex3f(-0.154509,0.475528,-0.5);
                                glNormal3f(-0.557536,0.405073,-0.724617);
                                glVertex3f(-0.404509,0.293893,-0.5);
                                glNormal3f(-0.557536,0.405073,0.724617);
                                glVertex3f(-0.404509,0.293893,0.5);
                                glNormal3f(-0.21296,0.655422,0.724617);
                                glVertex3f(-0.154509,0.475528,0.5);
                                glNormal3f(-0.557536,0.405073,-0.724617);
                                glVertex3f(-0.404509,0.293893,-0.5);
                                glNormal3f(-0.689152,-4.31905e-008,-0.724617);
                                glVertex3f(-0.5,-4.37114e-008,-0.5);
                                glNormal3f(-0.689152,-4.31905e-008,0.724617);
                                glVertex3f(-0.5,-4.37114e-008,0.5);
                                glNormal3f(-0.557536,0.405073,0.724617);
                                glVertex3f(-0.404509,0.293893,0.5);
                                glNormal3f(-0.689152,-4.31905e-008,-0.724617);
                                glVertex3f(-0.5,-4.37114e-008,-0.5);
                                glNormal3f(-0.557535,-0.405073,-0.724617);
                                glVertex3f(-0.404508,-0.293893,-0.5);
                                glNormal3f(-0.557535,-0.405073,0.724617);
                                glVertex3f(-0.404508,-0.293893,0.5);
                                glNormal3f(-0.689152,-4.31905e-008,0.724617);
                                glVertex3f(-0.5,-4.37114e-008,0.5);
                                glNormal3f(-0.557535,-0.405073,-0.724617);
                                glVertex3f(-0.404508,-0.293893,-0.5);
                                glNormal3f(-0.21296,-0.655422,-0.724617);
                                glVertex3f(-0.154509,-0.475528,-0.5);
                                glNormal3f(-0.21296,-0.655422,0.724617);
                                glVertex3f(-0.154509,-0.475528,0.5);
                                glNormal3f(-0.557535,-0.405073,0.724617);
                                glVertex3f(-0.404508,-0.293893,0.5);
                                glNormal3f(-0.21296,-0.655422,-0.724617);
                                glVertex3f(-0.154509,-0.475528,-0.5);
                                glNormal3f(0.21296,-0.655422,-0.724617);
                                glVertex3f(0.154509,-0.475528,-0.5);
                                glNormal3f(0.21296,-0.655422,0.724617);
                                glVertex3f(0.154509,-0.475528,0.5);
                                glNormal3f(-0.21296,-0.655422,0.724617);
                                glVertex3f(-0.154509,-0.475528,0.5);
                                glNormal3f(0.21296,-0.655422,-0.724617);
                                glVertex3f(0.154509,-0.475528,-0.5);
                                glNormal3f(0.557536,-0.405073,-0.724617);
                                glVertex3f(0.404509,-0.293892,-0.5);
                                glNormal3f(0.557536,-0.405073,0.724617);
                                glVertex3f(0.404509,-0.293892,0.5);
                                glNormal3f(0.21296,-0.655422,0.724617);
                                glVertex3f(0.154509,-0.475528,0.5);
                                glNormal3f(0.557536,-0.405073,-0.724617);
                                glVertex3f(0.404509,-0.293892,-0.5);
                                glNormal3f(0.689152,6.47858e-008,-0.724617);
                                glVertex3f(0.5,0,-0.5);
                                glNormal3f(0.689152,6.47858e-008,0.724617);
                                glVertex3f(0.5,0,0.5);
                                glNormal3f(0.557536,-0.405073,0.724617);
                                glVertex3f(0.404509,-0.293892,0.5);

                            glEnd ();

                        glPopMatrix ();

                    glPopMatrix ();

                glPopMatrix ();

            glPopMatrix ();

        glPopMatrix ();

    glPopMatrix ();

glPopMatrix ();

}

