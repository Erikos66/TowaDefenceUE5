#pragma once

UENUM(BlueprintType)
enum class EHexTileType : uint8
{
	TowerTile    UMETA(DisplayName = "Tower Tile"),
	BaseTile     UMETA(DisplayName = "Base Tile"),
	PathTile     UMETA(DisplayName = "Path Tile"),
	EnemySpawnTile UMETA(DisplayName = "Enemy Spawn Tile")
};
