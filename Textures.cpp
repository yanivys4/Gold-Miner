#include "Textures.h"

//=============================================================================
Textures & Textures::instance()
{
	static Textures textures;
	return textures;
}

//=============================================================================
sf::Texture & Textures::operator[](texturesNames t)
{
	return m_textures[t];
}

//=============================================================================
Textures::Textures()
{
	m_textures.resize(NUM_OF_TEXTURES);

	for (size_t i = 0; i < NUM_OF_TEXTURES; ++i)
	{
		m_textures[i].loadFromFile(texturesImages[i]);
		m_textures[i].setSmooth(true);
	}
}

