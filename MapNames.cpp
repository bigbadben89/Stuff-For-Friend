#include "pch.h"

char isMapName[100]; // Array para armazenar o nome do mapa

int isMapNameFunction(int MapID) {
    switch (MapID) {
    case 0:
        snprintf(isMapName, sizeof(isMapName), "%s", "Raigo");
        break;
    case 1:
        snprintf(isMapName, sizeof(isMapName), "%s", "Light map1");
        break;
    case 2:
        snprintf(isMapName, sizeof(isMapName), "%s", "Dark map1");
        break;
    case 3:
        snprintf(isMapName, sizeof(isMapName), "%s", "D1 light portal");
        break;
    case 4:
        snprintf(isMapName, sizeof(isMapName), "%s", "Lich Room");
        break;
    case 5:
        snprintf(isMapName, sizeof(isMapName), "%s", "Cornwell");
        break;
    case 6:
        snprintf(isMapName, sizeof(isMapName), "%s", "Light Asmo Room");
        break;
    case 7:
        snprintf(isMapName, sizeof(isMapName), "%s", "Argilla");
        break;
    case 8:
        snprintf(isMapName, sizeof(isMapName), "%s", "Knight Room");
        break;
    case 9:
        snprintf(isMapName, sizeof(isMapName), "%s", "D2");
        break;
    case 10:
        snprintf(isMapName, sizeof(isMapName), "%s", "D2");
        break;
    case 11:
        snprintf(isMapName, sizeof(isMapName), "%s", "Kimu room");
        break;
    case 12:
        snprintf(isMapName, sizeof(isMapName), "%s", "Cloron");
        break;
    case 13:
        snprintf(isMapName, sizeof(isMapName), "%s", "Cloron");
        break;
    case 14:
        snprintf(isMapName, sizeof(isMapName), "%s", "Cloron");
        break;
    case 15:
        snprintf(isMapName, sizeof(isMapName), "%s", "FL");
        break;
    case 16:
        snprintf(isMapName, sizeof(isMapName), "%s", "FL");
        break;
    case 17:
        snprintf(isMapName, sizeof(isMapName), "%s", "FL");
        break;
    case 18:
        snprintf(isMapName, sizeof(isMapName), "%s", "Proelium");
        break;
    case 19:
        snprintf(isMapName, sizeof(isMapName), "%s", "Light map2");
        break;
    case 20:
        snprintf(isMapName, sizeof(isMapName), "%s", "dark map2");
        break;
    case 21:
        snprintf(isMapName, sizeof(isMapName), "%s", "Maitreyan");
        break;
    case 22:
        snprintf(isMapName, sizeof(isMapName), "%s", "Maitreyan boss raum");
        break;
    case 23:
        snprintf(isMapName, sizeof(isMapName), "%s", "AidionNekria");
        break;
    case 24:
        snprintf(isMapName, sizeof(isMapName), "%s", "AidionNekria floor2");
        break;
    case 25:
        snprintf(isMapName, sizeof(isMapName), "%s", "Elemental Cave");
        break;
    case 26:
        snprintf(isMapName, sizeof(isMapName), "%s", "RuberChaos");
        break;
    case 27:
        snprintf(isMapName, sizeof(isMapName), "%s", "??????");
        break;
    case 28:
        snprintf(isMapName, sizeof(isMapName), "%s", "Light map3");
        break;
    case 29:
        snprintf(isMapName, sizeof(isMapName), "%s", "dark map3");
        break;
    case 30:
        snprintf(isMapName, sizeof(isMapName), "%s", "CANTA");
        break;
    case 31:
        snprintf(isMapName, sizeof(isMapName), "%s", "20-30 Dungeon light");
        break;
    case 32:
        snprintf(isMapName, sizeof(isMapName), "%s", "20-30 Dungeon dark");
        break;
    case 33:
        snprintf(isMapName, sizeof(isMapName), "%s", "Fedion Temple");
        break;
    case 34:
        snprintf(isMapName, sizeof(isMapName), "%s", "Kalamus House");
        break;
    case 35:
        snprintf(isMapName, sizeof(isMapName), "%s", "Apulune");
        break;
    case 36:
        snprintf(isMapName, sizeof(isMapName), "%s", "Iris");
        break;
    case 37:
        snprintf(isMapName, sizeof(isMapName), "%s", "Stigma");
        break;
    case 38:
        snprintf(isMapName, sizeof(isMapName), "%s", "AZ");
        break;
    case 39:
        snprintf(isMapName, sizeof(isMapName), "%s", "Arena Battle");
        break;
    case 40:
        snprintf(isMapName, sizeof(isMapName), "%s", "Arena");
        break;
    case 41:
        snprintf(isMapName, sizeof(isMapName), "%s", "Prison");
        break;
    case 42:
        snprintf(isMapName, sizeof(isMapName), "%s", "Auction House");
        break;
    case 43:
        snprintf(isMapName, sizeof(isMapName), "%s", "Locus Graveyard");
        break;
    case 44:
        snprintf(isMapName, sizeof(isMapName), "%s", "Lanhaar");
        break;
    case 45:
        snprintf(isMapName, sizeof(isMapName), "%s", "DD1");
        break;
    case 46:
        snprintf(isMapName, sizeof(isMapName), "%s", "DD2");
        break;
    case 47:
        snprintf(isMapName, sizeof(isMapName), "%s", "Jungle");
        break;
    case 48:
        snprintf(isMapName, sizeof(isMapName), "%s", "CT");
        break;
    case 49:
        snprintf(isMapName, sizeof(isMapName), "%s", "CT");
        break;
    case 50:
        snprintf(isMapName, sizeof(isMapName), "%s", "GRB Map");
        break;
    case 51:
        snprintf(isMapName, sizeof(isMapName), "%s", "Light Guildhouse");
        break;
    case 52:
        snprintf(isMapName, sizeof(isMapName), "%s", "Dark Guildhouse");
        break;
    case 53:
        snprintf(isMapName, sizeof(isMapName), "%s", "Light Managment Office");
        break;
    case 54:
        snprintf(isMapName, sizeof(isMapName), "%s", "Dark Managment Office");
        break;
    case 55:
        snprintf(isMapName, sizeof(isMapName), "%s", "SkyCity");
        break;
    case 56:
        snprintf(isMapName, sizeof(isMapName), "%s", "SkyCity");
        break;
    case 57:
        snprintf(isMapName, sizeof(isMapName), "%s", "SkyCity");
        break;
    case 58:
        snprintf(isMapName, sizeof(isMapName), "%s", "SkyCity");
        break;
    case 59:
        snprintf(isMapName, sizeof(isMapName), "%s", "Fedion Temple");
        break;
    case 60:
        snprintf(isMapName, sizeof(isMapName), "%s", "Soccer Stadium");
        break;
    case 61:
        snprintf(isMapName, sizeof(isMapName), "%s", "Stigma");
        break;
    case 62:
        snprintf(isMapName, sizeof(isMapName), "%s", "KH");
        break;
    case 63:
        snprintf(isMapName, sizeof(isMapName), "%s", "AZ");
        break;
    case 64:
        snprintf(isMapName, sizeof(isMapName), "%s", "Isla");
        break;
    case 65:
        snprintf(isMapName, sizeof(isMapName), "%s", "??????");
        break;
    case 66:
        snprintf(isMapName, sizeof(isMapName), "%s", "Caelum Sacra");
        break;
    case 67:
        snprintf(isMapName, sizeof(isMapName), "%s", "Caelum Sacra");
        break;
    case 68:
        snprintf(isMapName, sizeof(isMapName), "%s", "Valdemar");
        break;
    case 69:
        snprintf(isMapName, sizeof(isMapName), "%s", "Palaion Regnum");
        break;
    case 70:
        snprintf(isMapName, sizeof(isMapName), "%s", "Kanos");
        break;
    case 71:
        snprintf(isMapName, sizeof(isMapName), "%s", "Servus Queen");
        break;
    case 72:
        snprintf(isMapName, sizeof(isMapName), "%s", "Caput Queen");
        break;
    case 73:
        snprintf(isMapName, sizeof(isMapName), "%s", "Naiad Spot");
        break;
    case 74:
        snprintf(isMapName, sizeof(isMapName), "%s", "CTI II");
        break;
    case 75:
        snprintf(isMapName, sizeof(isMapName), "%s", "CTI II");
        break;
    case 76:
        snprintf(isMapName, sizeof(isMapName), "%s", "Senechio");
        break;
    case 77:
        snprintf(isMapName, sizeof(isMapName), "%s", "Tears Marsh");
        break;
    case 78:
        snprintf(isMapName, sizeof(isMapName), "%s", "Stable Erde");
        break;
    case 79:
        snprintf(isMapName, sizeof(isMapName), "%s", "Stable Erde");
        break;
    case 80:
        snprintf(isMapName, sizeof(isMapName), "%s", "Dwater Borderland");
        break;
    case 81:
        snprintf(isMapName, sizeof(isMapName), "%s", "Canyon");
        break;
    case 82:
        snprintf(isMapName, sizeof(isMapName), "%s", "Museum");
        break;
    case 83:
        snprintf(isMapName, sizeof(isMapName), "%s", "SC Map");
        break;
    case 84:
        snprintf(isMapName, sizeof(isMapName), "%s", "Robot Map");
        break;
    case 85:
        snprintf(isMapName, sizeof(isMapName), "%s", "Link of Evil");
        break;
    case 86:
        snprintf(isMapName, sizeof(isMapName), "%s", "Free For All");
        break;
    case 87:
        snprintf(isMapName, sizeof(isMapName), "%s", "Secret Arena");
        break;
    case 88:
        snprintf(isMapName, sizeof(isMapName), "%s", "Desert Spa");
        break;
    case 89:
        snprintf(isMapName, sizeof(isMapName), "%s", "Cryptic Throne");
        break;
    case 90:
        snprintf(isMapName, sizeof(isMapName), "%s", "Goddess Siege");
        break;
    case 91:
        snprintf(isMapName, sizeof(isMapName), "%s", "Dark Stable Erde");
        break;
    case 92:
        snprintf(isMapName, sizeof(isMapName), "%s", "Goblins Domain");
        break;
    case 93:
        snprintf(isMapName, sizeof(isMapName), "%s", "Ore  Islands");
        break;
    case 94:
        snprintf(isMapName, sizeof(isMapName), "%s", "Pixies Enclave");
        break;
    case 95:
        snprintf(isMapName, sizeof(isMapName), "%s", "Death Valley");
        break;
    case 96:
        snprintf(isMapName, sizeof(isMapName), "%s", "SkyCity");
        break;
    case 97:
        snprintf(isMapName, sizeof(isMapName), "%s", "Raigo Light Arena");
        break;
    case 98:
        snprintf(isMapName, sizeof(isMapName), "%s", "Raigo Dark Arena");
        break;
    case 99:
        snprintf(isMapName, sizeof(isMapName), "%s", "Death Map");
        break;
    case 100:
        snprintf(isMapName, sizeof(isMapName), "%s", "Stable Erde");
        break;
    case 101:
        snprintf(isMapName, sizeof(isMapName), "%s", "Jungle");
        break;
    case 102:
        snprintf(isMapName, sizeof(isMapName), "%s", "Jungle");
        break;
    case 103:
        snprintf(isMapName, sizeof(isMapName), "%s", "Jungle");
        break;
    case 104:
        snprintf(isMapName, sizeof(isMapName), "%s", "Water Cave");
        break;
    case 105:
        snprintf(isMapName, sizeof(isMapName), "%s", "SkyCity");
        break;
    case 106:
        snprintf(isMapName, sizeof(isMapName), "%s", "SkyCity");
        break;
    case 107:
        snprintf(isMapName, sizeof(isMapName), "%s", "Poison Forest");
        break;
    case 108:
        snprintf(isMapName, sizeof(isMapName), "%s", "Cave");
        break;
    case 109:
        snprintf(isMapName, sizeof(isMapName), "%s", "Poison Forest");
        break;
    case 110:
        snprintf(isMapName, sizeof(isMapName), "%s", "New SkyCity");
        break;
    case 111:
        snprintf(isMapName, sizeof(isMapName), "%s", "SkyCity");
        break;
    case 112:
        snprintf(isMapName, sizeof(isMapName), "%s", "Cave");
        break;
    case 113:
        snprintf(isMapName, sizeof(isMapName), "%s", "Mirthan");
        break;
    case 114:
        snprintf(isMapName, sizeof(isMapName), "%s", "Desert");
        break;
    case 115:
        snprintf(isMapName, sizeof(isMapName), "%s", "Storms");
        break;
    case 116:
        snprintf(isMapName, sizeof(isMapName), "%s", "Pet");
        break;
    case 117:
        snprintf(isMapName, sizeof(isMapName), "%s", "Palaion Regnum");
        break;
    case 118:
        snprintf(isMapName, sizeof(isMapName), "%s", "Arena");
        break;
    default:
        return -1;
    }

    return 0;
}