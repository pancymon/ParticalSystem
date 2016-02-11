#ifndef PSMANAGER_H
#define PSMANAGER_H

#include<vector>
#include"repeller.h"
#include"ParticalSystem.h"

using namespace std;

class PSManager {
public:
	static PSManager* Instance();
	
	void AddRepeller();

	vector<Repeller> m_Repellers;

	vector<ParticleSystem*> m_ParticalSystems;

	void Update(Time elapsed);

	void AddPS(ParticleSystem* ps);

	void Draw(RenderWindow* window);

	//void ChangeNumber();

private:

	Clock clock;

	//singleton
	PSManager() { clock.restart(); };
	PSManager(PSManager const&) {};
	PSManager& operator=(PSManager const&) {};
	static PSManager* m_pInstance;

};

#endif
