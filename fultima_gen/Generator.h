#pragma once
#include <string>

class Generator
{
private:
	//JSON sciezki do plikow bazowych:
	std::string _basic_weapons_path; //teoretycznie powinno byæ: json_files/basic/Basic_Weapons.json
	std::string _basic_armors_path; //json_files/basic/Basic_Armors.json
	std::string _basic_qualities_path; //json_files/basic/Basic_Qualities.json
public:
	Generator() : _basic_weapons_path("json_files/basic/Basic_Weapons.json"),
		_basic_armors_path("json_files/basic/Basic_Armors.json"),
		_basic_qualities_path("json_files/basic/Basic_Qualities.json") {
	}

	std::string getBasicWeaponsPath() { return _basic_weapons_path; }
	std::string getBasicArmorsPath() { return _basic_armors_path; }
	std::string getBasicQualitiesPath() { return _basic_qualities_path; }
	//INFO: w JSONach w broni jest przechowywana pod ID 6 i 7 podobna rzecz, ale ta dro¿sza ma u¿ywaæ ENRAGED lub POISONED, a ta tañsza reszty

	//INFO: w JSONie pod 1, ma byæ status effect jako dokoñczenie do desc co siê tam znaduje string z desc + status effect. Pod 2 jest s¹ rezistym pod 5 s¹ dual rezisty bez physicala do wyboru
	//		pod 7 s¹ bez physicala zaœ immune. 
};

