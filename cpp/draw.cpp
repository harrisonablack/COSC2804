#include "mcpp/block.h"
#include "mcpp/coordinate.h"
#include <mcpp/mcpp.h>

mcpp::Coordinate ORIGIN{0, 0, 0};
int PYRAMID_HEIGHT = 50;
mcpp::MinecraftConnection mc;

int main() {
  mcpp::BlockType block;
  // for (int i = 0; i < 100; ++i) {
  block = mcpp::BlockType(1);

  for (int x = 0; x < 512; ++x) {
    for (int z = 0; z < 512; ++z) {
      for (int y = 0; y < 300; ++y) {

        // Every 16 blocks, generated edges on horizontal
        if (y % 5 == 0) {
          if ((x % 5 == 0) || (z % 5 == 0)) {
            mc.setBlock(mcpp::Coordinate(x, y, z), block);
          }
        }

        if ((x % 5 == 0 && z % 5 == 0)) {
          mc.setBlock(mcpp::Coordinate(x, y, z), block);
        }

        // mc.setBlock(mcpp::Coordinate(x, y, z), mcpp::Blocks::AIR);
      }
    }
  }

  // std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  //   for (int x = 0; x < 16; ++x) {
  //     for (int z = 0; z < 16; ++z) {
  //       for (int y = -64; y < 384; ++y) {
  //         mc.setBlock(mcpp::Coordinate(x, y, z), mcpp::Blocks::AIR);
  //       }
  //     }
  //   }
  // }

  // for (int x = 0; x < 16; ++x) {
  //   for (int z = 0; z < 16; ++z) {
  //     for (int y = -64; y < 384; ++y) {

  //       // Every 16 blocks, generated edges on horizontal
  //       if (y % 16 == 0) {
  //         if ((x == 0 || x == 15) || (z == 0 || z == 15)) {
  //           mc.setBlock(mcpp::Coordinate(x, y, z), mcpp::Blocks::GLASS);
  //         }
  //       }

  //       if ((x == 0 && z == 0) || (x == 0 && z == 15) || (x == 15 && z == 0)
  //       ||
  //           (x == 15 && z == 15)) {
  //         mc.setBlock(mcpp::Coordinate(x, y, z), mcpp::Blocks::GLASS);
  //       }

  //       // mc.setBlock(mcpp::Coordinate(x, y, z), mcpp::Blocks::AIR);
  //     }
  //   }
  // }
  mc.postToChat("Placed blocks");
}

// void make_ring(mcpp::Coordinate base_pt, int side_len) {
//   // Flat plane
//   mc.setBlocks(base_pt, base_pt + mcpp::Coordinate(side_len, 0, side_len),
//   mcpp::Blocks::SANDSTONE);

//   // Air inside to make border
//   base_pt = base_pt + mcpp::Coordinate(1, 0, 1);
//   mc.setBlocks(base_pt, base_pt + mcpp::Coordinate(side_len - 2, 0, side_len
//   - 2),
//                mcpp::Blocks::AIR);
// }
