#include "BIS_AddonInfo.hpp"
class CfgPatches {
    class D37_FPV {
        requiredAddons[] = {};
        requiredVersion = 0.1;
        units[] = {"B_FPV_UAV"};
        weapons[] = {"FakeDroneWeapon"};
        author="Dankan37";
    };
};

class cfgAmmo {
    class R_MRAAWS_HEAT_F;
    class R_FPV_fakeRocket: R_MRAAWS_HEAT_F {
        timeToLive = 69420;
        submunitionInitSpeed = 1400;
        indirectHit = 23;
        indirectHitRange = 5;

        submunitionAmmo = "FPV_ammo_Penetrator_MRAAWS";
    };

    class ammo_Penetrator_MRAAWS;
    class FPV_ammo_Penetrator_MRAAWS: ammo_Penetrator_MRAAWS {
        timeToLive = 0.5;
        hit = 550;
        simulationStep = 0.005;
    };
};

class cfgWeapons {
    class FakeWeapon;
    class FakeDroneWeapon: FakeWeapon {
        displayName = "Detonate";
        class Eventhandlers {
            fired = "triggerAmmo ((_this # 0) getVariable 'attachedShell');";
        }
    };
};

class cfgVehicles {
    class UAV_01_base_F;
    class B_UAV_01_F:UAV_01_base_F {
        class Eventhandlers;
        class assembleInfo;
    };
    class B_FPV_UAV: B_UAV_01_F {
        author = "Dankan37";
        displayname = "AR-2 Darter (RPG)";
        weapons[] = {"FakeDroneWeapon"};
        magazines[] = {"FakeMagazine"};

        enableManualFire = 0;
        limitedSpeedCoef = 0.25;

        class CargoTurret {};
        class NewTurret {};
        class PilotCamera{};
        class Turrets {};
        

        class assembleInfo: assembleInfo {
            dissasembleTo[] = {"B_UAV_FPV_backpack_F"};
            primary = 0;
        };

        hasGunner = 0;
		showgunneroptics = 0;

        class Eventhandlers {
            class D37_FPV {
                init = "[_this # 0] call D37_FPV_fnc_initDrone;";
            }
        }
    };

    class O_FPV_UAV: B_FPV_UAV {
        crew = "O_UAV_AI";
        displayName = "Tayran AR-2 (RPG)";
        editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\O_UAV_01_F.jpg";
        faction = "OPF_F";
        hiddenSelectionsTextures[] = {"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_OPFOR_CO.paa"};
        side = 0;
        textureList[] = {"Opfor",1};
        typicalCargo[] = {"O_UAV_AI"};
    };

    class I_FPV_UAV: B_FPV_UAV {
        crew = "I_UAV_AI";
        editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\I_UAV_01_F.jpg";
        faction = "IND_F";
        hiddenSelectionsTextures[] = {"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_INDP_CO.paa"};
        side = 2;
        typicalCargo[] = {"I_Soldier_lite_F"};
        textureList[] = {"Indep",1};
    };

    class Weapon_Bag_Base;
    class B_UAV_01_backpack_F: Weapon_Bag_Base {
        class assembleInfo;
    };
    class I_UAV_01_backpack_F: Weapon_Bag_Base {
        class assembleInfo;
    };
    class O_UAV_01_backpack_F: Weapon_Bag_Base {
        class assembleInfo;
    };

    class B_UAV_FPV_backpack_F: B_UAV_01_backpack_F {
        author = "Dankan37";
        displayName = "UAV Bag (AR-2 RPG) [NATO]";
        mass = 250;
        class assembleInfo:assembleInfo {
            assembleTo = "B_FPV_UAV";
        };
    };

    class I_UAV_FPV_backpack_F: I_UAV_01_backpack_F {
        author = "Dankan37";
        displayName = "UAV Bag (AR-2 RPG) [AAF]";
        mass = 250;
        class assembleInfo:assembleInfo {
            assembleTo = "I_FPV_UAV";
        };
    };

    class O_UAV_FPV_backpack_F: O_UAV_01_backpack_F {
        author = "Dankan37";
        displayName = "UAV Bag (AR-2 RPG) [CSAT]";
        mass = 250;
        class assembleInfo:assembleInfo {
            assembleTo = "O_FPV_UAV";
        };
    };
};

class CfgFunctions
{
	class D37_FPV
	{
		class functions
		{
			file = "D37_FPV";
            class initDrone {};
		};
	};
};
