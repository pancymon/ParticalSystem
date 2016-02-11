#include <stddef.h>  // defines NULL
#include"PSManager.h"
PSManager* PSManager::m_pInstance = 0;

PSManager* PSManager::Instance()
{
	if (!m_pInstance)
		m_pInstance = new PSManager;
	return m_pInstance;

}

void PSManager::AddRepeller()
{
	m_Repellers.push_back(Repeller());
}

void PSManager::AddPS(ParticleSystem* ps)
{
	m_ParticalSystems.push_back(ps);
}

void PSManager::Draw(RenderWindow* window)
{
	for (int i = 0; i < m_ParticalSystems.size(); i++)
	{
		RenderStates renderState;
		renderState.texture = &(m_ParticalSystems[i]->m_Texture);
		window->draw(*m_ParticalSystems[i], renderState);
	}
}

void PSManager::Update(Time elapsed)
{
	//Time elapsed = clock.restart();
	for (int i = 0; i < m_ParticalSystems.size(); i++)
	{
		m_ParticalSystems[i]->update(elapsed);
	}
}