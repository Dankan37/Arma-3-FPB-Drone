_veh = param[0, objNull, [objNull]];
if(isNull _veh) exitWith {};
//createVehicleCrew _veh;

_pos = position _veh;
_shell = "R_FPV_fakeRocket" createVehicle _pos; //R_MRAAWS_HEAT_F R_MRAAWS_HEAT55_F
_shell enableSimulation false;
_shell attachTo [_veh, [0,0.17,-0.13]];
_veh setVariable ["attachedShell", _shell];

_veh addEventHandler ["Killed", {
	_this spawn {
		sleep 0.1;
		deleteVehicle (_this # 0);
	};
}];

_veh addEventHandler ["Hit", {
	params ["_unit", "_source", "_damage", "_instigator"];
	if(_damage > 0.3) then {
		_shell = _unit getVariable ["attachedShell", _shell];
		triggerAmmo _shell;
	};
}];
