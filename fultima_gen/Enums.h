#pragma once
enum class Atributes {
	WLP = 0, INS = 1, DEX = 2, MIG = 3 //Jak w JSONIe jest cokolwiek powy¿ej 3 to zmusiæ generator do przypisania wartoœci która jest tam wpisana
};
enum class DMGType {
	PHYSICAL = 0, AIR = 1, BOLT = 2, DARK = 3, EARTH = 4, FIRE = 5, ICE = 6, LIGHT = 7, POISON = 8
};
enum class StatusEffect { //Jeszcze nie wiem czy to potrzebne ale mo¿e siê przyda na potem
	DAZED = 0, 
	ENRAGED = 4, // Po³aczenie: Dazed + Slow. MOCNIEJSZE NI¯ PO PROSTU POJEDYNCZE!! PILNOWAÆ W KODZIE
	POISONED = 5, // Po³¹czenie: Shaken + Weak. tak samo jak wy¿ej
	SHAKEN = 1, 
	SLOW = 2, 
	WEAK = 3
};
enum class WeaponType {
	ARCANE = 0, BOW = 1, BRAWL = 2, DAGGER = 3, FIREARM = 4, FLAIL = 5, HEAVY = 6, SPEAR = 7, SWORD = 8, THROWN = 9
};