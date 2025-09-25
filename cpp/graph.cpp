#include "mcpp/block.h"
#include "mcpp/coordinate.h"
#include "mcpp/mcpp.h"

mcpp::MinecraftConnection mc;
mcpp::Coordinate ORIGIN{0, 0, 0};
mcpp::Coordinate MIN{-10, -10, 0};
mcpp::Coordinate MAX{10, 10, 0};

std::vector<mcpp::Coordinate> draw(mcpp::Coordinate& min, mcpp::Coordinate& max, mcpp::Coordinate& origin){
  std::vector<mcpp::Coordinate> point;

  for (int i = min.x; i < max.x; ++i) {
    point.push_back(mcpp::Coordinate(i,2*i,0));

  }

  return point;
}

void place(std::vector<mcpp::Coordinate>& cord) {
  for (mcpp::Coordinate c : cord) {
    mc.setBlock(c, mcpp::Blocks::STONE);
    mc.postToChat("Placing block");

  }
}

int main() {
  std::vector<mcpp::Coordinate> points = draw(MIN, MAX, ORIGIN);
  place(points);
  return 0;
}
