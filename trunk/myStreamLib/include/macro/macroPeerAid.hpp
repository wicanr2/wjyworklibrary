#ifndef MACRO_PEER_AID_HPP
#define MACRO_PEER_AID_HPP

#define MACRO_PEER_ADD_1(id,_ip,_vport,_aport)\
	do{\
		char ip[]=#_ip;\
		char vport[]=#_vport;\
		char aport[]=#_aport;\
		PI_AddPeer(id, ip, vport, aport );\
	}while(0)

#define MACRO_PEER_ADD_2(id,_ip,_vport,_aport,_pport)\
	do{\
		char ip[]=#_ip;\
		char vport[]=#_vport;\
		char aport[]=#_aport;\
		char pport[]=#_pport;\
		PI_AddPeerExt(id, ip, vport, aport, pport );\
	}while(0)

#define MACRO_PEER_ADD_3(id,_ip,_vport,_aport,_pport,_uuid,_name)\
	do{\
		char ip[]=#_ip;\
		char vport[]=#_vport;\
		char aport[]=#_aport;\
		char pport[]=#_pport;\
		char uuid[]=#_uuid;\
		char name[]=#_name;\
		PI_AddPeerExt2(id, ip, vport, aport, pport, uuid, name );\
	}while(0)

#endif
