#include "Sounds.h"

sf::Music Sounds::m_backgroundMusic;

//=============================================================================
Sounds & Sounds::instance()
{
	static Sounds sounds;
	return sounds;
}

//=============================================================================
sf::SoundBuffer & Sounds::operator[](SoundsNames s)
{
	return m_sounds[s];
}

//=============================================================================
sf::Music & Sounds::getbackgroundMusic()
{
	return m_backgroundMusic;
}

//=============================================================================
Sounds::Sounds()
{
	//initialize the background music once in the whole program
	if (!m_backgroundMusic.openFromFile("Sounds/BackgroundMusic.ogg"))
		exit(EXIT_FAILURE);

	m_sounds.resize(NUM_OF_SOUNDS);

	//initialize the sound buffers once in the whole program
	for (size_t i = 0; i < NUM_OF_SOUNDS; ++i)
	{
		if (!m_sounds[i].loadFromFile(SoundFiles[i]))
			exit(EXIT_FAILURE);
	}
}