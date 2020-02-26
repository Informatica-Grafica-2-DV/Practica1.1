#include "Scene.h"
#include "CheckML.h"
#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

#pragma region includesImplementación
#include "Resources.h"
#pragma endregion


using namespace glm;
//-------------------------------------------------------------------------

void Scene::init()
{ 
	setGL();  // OpenGL settingsu
	gObjects.push_back(new EjesRGB(400.0)); //Ejes RGB
	switch (mId)
	{
	case 0:
		initScene0();
		break;
	case 1:
		initScene1();
		break;
	default:
		break;
	}


	// allocate memory and load resources
    // Lights
    // Textures
    // Graphics objects (entities) of the scene


}

void Scene::chargeTextures() {

	for (auto& image : Resources::images_) {
		Texture* currTexture = new Texture();
		currTexture->load(image.fileName);
		gTextures.push_back(currTexture);
	}
}

void Scene::initScene1() {
	chargeTextures();
	gObjects.push_back(new Estrella3D(100, 6, 150));
	gObjects.back()->setTexture(gTextures[Resources::BaldosaP]);

}

void Scene::initScene0() {
#pragma region Ejercicio1
	gObjects.push_back(new Poligono(3, 300)); //Triángulo
	gObjects.back()->setMColor({ 255.0, 255.0, 0.0, 1.0 }); //Asignamos amarillo al triángulo
	gObjects.push_back(new Poligono(360, 300)); //Circunferencia
	gObjects.back()->setMColor({ 255.0, 0.0, 255.0, 1.0 }); //Asignamos magenta al triángulo
#pragma endregion
#pragma region Ejercicio2
	gObjects.push_back(new Sierpinski(300, 10000));
	gObjects.back()->setMColor(dvec4(1.0, 1.0, 0.0, 1.0)); //Asignamos magenta a Sierpinski
#pragma endregion
#pragma region Ejercicio3
	gObjects.push_back(new TrianguloRGB(60));
#pragma endregion
#pragma region Ejercicio4
	gObjects.push_back(new RectanguloRGB(800, 600));
	gObjects.back()->setModelMat(translate(gObjects.back()->modelMat(), dvec3(0.0, 0.0, -100.0)));
#pragma endregion
}
//-------------------------------------------------------------------------
void Scene::free() 
{ // release memory and resources   

	for (Abs_Entity* el : gObjects)
	{
		delete el;  el = nullptr;
	}
	gObjects.clear();
	for (int i = 0; i < gTextures.size(); ++i) {
		delete gTextures.at(i);
		gTextures[i] = nullptr;
	}
	gTextures.clear();
}
//-------------------------------------------------------------------------
void Scene::setGL() 
{
	// OpenGL basic setting
	glClearColor(0.0, 0.0, 0.0, 1.0);  // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);  // enable Depth test
	glEnable(GL_TEXTURE_2D);
}
//-------------------------------------------------------------------------
void Scene::resetGL() 
{
	glClearColor(.0, .0, .0, .0);  // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);  // disable Depth test 	
	glDisable(GL_TEXTURE_2D);  // disable Depth test 	
}
//-------------------------------------------------------------------------

void Scene::render(Camera const& cam) const 
{
	cam.upload();
	for (Abs_Entity* el : gObjects)
	{
	  el->render(cam.viewMat());
	}
}
//-------------------------------------------------------------------------

#pragma region Implementación
void Scene::update() {
	for (Abs_Entity* el : gObjects) {
		el->update();
	}
}

void Scene::setState(int id_) {
	mId = id_;
}
#pragma endregion

