#include "Entity.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Abs_Entity::upload(dmat4 const& modelViewMat) const 
{ 
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(modelViewMat));  // transfers modelView matrix to the GPU
}

#pragma region Implementación
/*void Abs_Entity::update() {

}*/
#pragma endregion


//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

EjesRGB::EjesRGB(GLdouble l): Abs_Entity()
{
  mMesh = Mesh::createRGBAxes(l);
}
//-------------------------------------------------------------------------

EjesRGB::~EjesRGB() 
{ 
	delete mMesh; mMesh = nullptr; 
};
//-------------------------------------------------------------------------

void EjesRGB::render(dmat4 const& modelViewMat) const 
{
	if (mMesh != nullptr) {
		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		glLineWidth(2);
		mMesh->render();
		glLineWidth(1);
	}
}

#pragma region Implementación Enunciado
#pragma region Poligono
Poligono::Poligono(GLuint numL_, GLdouble rd_) : numL(numL_), rd(rd_) {
	mMesh = Mesh::generaPoligono(numL, rd);
}

Poligono::~Poligono() {
	delete mMesh; mMesh = nullptr;
}
void Poligono::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		glColor3d(mColor.r, mColor.g, mColor.b);
		glLineWidth(2);
		mMesh->render();

		//Reseteamos aributos
		glLineWidth(1);
		glColor3d(1, 1, 1);
	}
}
#pragma endregion
#pragma region Sierpinski
Sierpinski::Sierpinski(GLdouble rd_, GLuint numP_) : numP(numP_), rd(rd_) {
	mMesh = Mesh::generaSierpinski(rd, numP);
}

Sierpinski::~Sierpinski() {
	delete mMesh; mMesh = nullptr;
}

void Sierpinski::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		glColor4dv(value_ptr(mColor));
		glPointSize(2);
		mMesh->render();

		//Reseteamos atributos
		glPointSize(1);
		glColor4dv(value_ptr(glm::dvec4(1.0, 1.0, 1.0, 1.0)));
	}
}
#pragma endregion
#pragma region TriánguloRGB
TrianguloRGB::TrianguloRGB(GLdouble rd_) : rd(rd_) {
	mMesh = Mesh::generaTrianguloRGB(rd);
}

TrianguloRGB::~TrianguloRGB() {
	delete mMesh; mMesh = nullptr;
}

void TrianguloRGB::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		glColor3d(mColor.r, mColor.g, mColor.b);
		glLineWidth(2);
		glPolygonMode(GL_BACK, GL_LINE); //Para que no se rellene la parte trasera del triángulo.
		mMesh->render();

		//Reseteamos aributos
		glLineWidth(1);
		glColor3d(1, 1, 1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}
//Se encarga del movimiento
void TrianguloRGB::update() {
	angulo++;
	posCfc.x = 300 * cos(radians(angulo));
	posCfc.y = 300 * sin(radians(angulo));
	setModelMat(translate(dmat4(1), posCfc));
	setModelMat(rotate(modelMat(), radians(angulo), dvec3(0.0, 0.0, 1.0)));
}
#pragma endregion

#pragma region RectánguloRGB

RectanguloRGB::RectanguloRGB(GLdouble w_, GLdouble h_) :width(w_), height(h_) {
	mMesh = Mesh::generaRectanguloRGB(width,height);
}

RectanguloRGB::~RectanguloRGB() {
	delete mMesh; mMesh = nullptr;
}

void RectanguloRGB::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		glColor3d(mColor.r, mColor.g, mColor.b);
		glLineWidth(2);
		glPolygonMode(GL_BACK, GL_LINE);
		mMesh->render();

		//Reseteamos aributos
		glLineWidth(1);
		glColor3d(1, 1, 1);
		glPolygonMode(GL_FRONT, GL_FILL);
	}
}

#pragma endregion

#pragma endregion
//-------------------------------------------------------------------------
 