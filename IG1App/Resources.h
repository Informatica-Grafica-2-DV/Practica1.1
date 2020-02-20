#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum TextureId
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
	Zelda,
	Size
};

static const vector<string> routes{
	{"../Bmps/baldosaC.bmp"},
	{"../Bmps/baldosaF.bmp"},
	{"../Bmps/baldosaP.bmp"},
	{"../Bmps/container.bmp"},
	{"../Bmps/grass.bmp"},
	{"../Bmps/papelC.bmp"},
	{"../Bmps/papelE.bmp"},
	{"../Bmps/windowC.bmp"},
	{"../Bmps/windowV.bmp"},
	{"../Bmps/Zelda.bmp"}
};


class Resources
{
public:
	static int textureSize() { return Size; };
};

