#pragma once
enum class Atributes {
	WLP = 0, INS = 1, DEX = 2, MIG = 3
};
enum class DMGType {
	PHYSICAL = 0, AIR = 1, BOLT = 2, DARK = 3, EARTH = 4, FIRE = 5, ICE = 6, LIGHT = 7, POISON = 8
};
enum class StatusEffect { //Jeszcze nie wiem czy to potrzebne ale mo¿e siê przyda na potem
	DAZED = 0, 
	ENRAGED = 1, // Po³aczenie: Dazed + Slow. MOCNIEJSZE NI¯ PO PROSTU POJEDYNCZE!! PILNOWAÆ W KODZIE
	POISONED = 2, // Po³¹czenie: Shaken + Weak. tak samo jak wy¿ej
	SHAKEN = 3, 
	SLOW = 4, 
	WEAK = 5
};