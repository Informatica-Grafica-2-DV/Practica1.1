#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class TextureId
{
	BaldosaC,
	BaldosaF,
	BaldosaP,
	Container,
	Grass,
	PapelC,
	PapelE,
	WindowC,
	WindowV,
	Zelda
};

struct Rutes
{
	string fileName;
	TextureId id;
	//Rutes(string fileName_,int id_) :
	//	fileName(fileName_), id(id_){}
};

static vector<Rutes> textureInfo{
	{"ruta", },
	{}
}
