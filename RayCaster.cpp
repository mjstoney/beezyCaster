#include "RayCaster.h"
#include <SFML/Graphics.hpp>
#include "Mat2.h"

void RayCaster::update(float dt) {
	pos = player->pos;
	dir = player->dir;
	if (keyH->aPressed || keyH->dPressed) {
		if (keyH->aPressed) rotate(-dt);
		if (keyH->dPressed) rotate(dt);
	}
}

void RayCaster::rotate(double dt)
{
	double c = cos(PLAYER_ROTATION * dt);
	double s = sin(PLAYER_ROTATION * dt);
	Mat2 rot(c, -s, s, c);
	plane = rot * plane;
}

void RayCaster::castRays() {
	renderLines.clear();
	double rad = atan2(dir.y, dir.x);
	double dTheta = FOV / double(SCREEN_WIDTH) * PI / 180.0;
	Vec2 rayPos = Vec2(pos.x * TILE_WIDTH, pos.y * TILE_HEIGHT);
	for (int x = -SCREEN_WIDTH / 2; x < SCREEN_WIDTH / 2; x++) {
		double cameraX = 2.5 * (double(x) / SCREEN_WIDTH / 2.0);
		double rayDirX = dir.x + plane.x * cameraX;
		double rayDirY = dir.y + plane.y * cameraX;
		Vec2 rayDir = Vec2(rayDirX, rayDirY);
		castRay(pos, rayDir, x, renderLines);
	}
}

void RayCaster::castRay(Vec2 orig, Vec2 dir, int renderX, std::vector<sf::VertexArray>& renderLines) {
	////// DDA //////

	Vec2 rayPos = orig;
	int mapX = int(rayPos.x);
	int mapY = int(rayPos.y);
	Vec2 rayDir = dir;
	Vec2 sideDist = Vec2();
	Vec2 deltaDist = Vec2(std::abs(1 / dir.x), std::abs(1 / dir.y));

	int stepX = 0;
	int stepY = 0;

	if (rayDir.x < 0) {
		stepX = -1;
		sideDist.x = (rayPos.x - double(mapX)) * deltaDist.x;
	}
	else {
		stepX = 1;
		sideDist.x = (double(mapX) + 1.0 - rayPos.x) * deltaDist.x;
	}

	if (rayDir.y < 0) {
		stepY = -1;
		sideDist.y = (rayPos.y - double(mapY)) * deltaDist.y;
	}
	else {
		stepY = 1;
		sideDist.y = (double(mapY) + 1.0 - rayPos.y) * deltaDist.y;
	}

	bool foundHit = false;
	int side = -1;
	while (!foundHit) {
		if (sideDist.x < sideDist.y) {
			sideDist.x += deltaDist.x;
			mapX += stepX;
			side = 0;
		}
		else {
			sideDist.y += deltaDist.y;
			mapY += stepY;
			side = 1;
		}
		if (MAP[mapY][mapX] != 0) {
			double distance = side == 0 ? sideDist.x - deltaDist.x : sideDist.y - deltaDist.y;

			foundHit = true;
			sf::VertexArray vArr(sf::Lines, 2);
			vArr[0] = sf::Vertex(sf::Vector2f(orig.x * TILE_WIDTH, orig.y * TILE_WIDTH), sf::Color::Yellow);
			vArr[1] = sf::Vertex(sf::Vector2f(float(orig.x * TILE_WIDTH + dir.x * distance * TILE_WIDTH), float(orig.y * TILE_WIDTH + dir.y * distance * TILE_HEIGHT)), sf::Color::Yellow);
			renderLines.push_back(vArr);

			double lineHeight = fmin(SCREEN_HEIGHT, SCREEN_HEIGHT / distance);
			lineHeight = fmax(lineHeight, 0);
			sf::Color c;
			if (side == 0) c = sf::Color(0x80438aff);
			else c = sf::Color(0x6c3575ff);
			// walls
			vArr[0] = sf::Vertex(sf::Vector2f(double(renderX + 1.5 * SCREEN_WIDTH), double(SCREEN_HEIGHT) / 2 + lineHeight / 2), c);
			vArr[1] = sf::Vertex(sf::Vector2f(double(renderX + 1.5 * SCREEN_WIDTH), double(SCREEN_HEIGHT) / 2 - lineHeight / 2), c);
			renderLines.push_back(vArr);
			// ceiling
			vArr[0] = sf::Vertex(sf::Vector2f(double(renderX + 1.5 * SCREEN_WIDTH), 0), sf::Color(0x5bb9f0ff));
			vArr[1] = sf::Vertex(sf::Vector2f(double(renderX + 1.5 * SCREEN_WIDTH), double(SCREEN_HEIGHT) / 2 - lineHeight / 2), sf::Color(0x5bb9f0ff));
			renderLines.push_back(vArr);
			// floor
			vArr[0] = sf::Vertex(sf::Vector2f(double(renderX + 1.5 * SCREEN_WIDTH), double(SCREEN_HEIGHT) / 2 + lineHeight / 2), sf::Color(0x536975ff));
			vArr[1] = sf::Vertex(sf::Vector2f(double(renderX + 1.5 * SCREEN_WIDTH), double(SCREEN_HEIGHT)), sf::Color(0x536975ff));
			renderLines.push_back(vArr);
		}
	}
}

void RayCaster::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (const sf::VertexArray &vArr : renderLines) {
		target.draw(vArr);
	}
}
