
#pragma once

#include "ItemHandler.h"
#include "../World.h"
#include "../Entities/Player.h"





class cItemAxeHandler :
	public cItemHandler
{
	typedef cItemHandler super;
public:
	cItemAxeHandler(int a_ItemType)
	: cItemHandler(a_ItemType)
	{
	}


	virtual float GetBlockBreakingStrength(BLOCKTYPE a_Block)
	{
		if (!IsBlockMaterialWood(a_Block) && !IsBlockMaterialPlants(a_Block) && !IsBlockMaterialVine(a_Block))
		{
			return super::GetBlockBreakingStrength(a_Block);
		}
		else
		{
			switch (m_ItemType)
			{
				case E_ITEM_WOODEN_AXE: return 2.0f;
				case E_ITEM_STONE_AXE:  return 4.0f;
				case E_ITEM_IRON_AXE:   return 6.0f;
				case E_ITEM_GOLD_AXE:   return 12.0f;
				case E_ITEM_DIAMOND_AXE: return 8.0f;
			}
		}
		ASSERT(!"Something is wrong here... Maybe they are axes out of a new material?");
		return 1.0f;
	}

} ;




