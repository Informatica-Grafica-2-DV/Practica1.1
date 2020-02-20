#include <iostream>
#include <string>
#include <vector>
#include <array>

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

static const string textureRute[TextureId::Size] = {
		"./Bmps/baldosaC.png",
		"./Bmps/baldosaF.png",
		"./Bmps/baldosaP.png",
		"./Bmps/Container.png",
		"./Bmps/Grass.png",
		"./Bmps/PapelC.png",
		"./Bmps/PapelE.png",
		"./Bmps/WindowC.png",
		"./Bmps/WindowV.png",
		"./Bmps/Zelda.png"
};

class Resources
{
public:
	static int textureSize() { return Size; };
};

