/* The copyright in this software is being made available under the BSD
 * License, included below. This software may be subject to other third party
 * and contributor rights, including patent rights, and no such rights are
 * granted under this license.
 *
 * Copyright (c) 2010-2019, ITU/ISO/IEC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of the ITU/ISO/IEC nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/** \file     Open3DTests.cpp
 *  \brief    Tests for the external library Open3DTests
 *  \details  See more details about it at
 *            https://github.com/intel-isl/Open3D
 *  \author   Pedro Garcia Freitas <pedro.gf@samsung.com>
 *  \date     2019-09-02
 */

#include <algorithm>
#include <string>
#include <vector>
#include "open3d/Open3D.h"
#include "gtest/gtest.h"

std::string resources_path = "../resources";


TEST(SimpleOpen3DTest, OneFlag) {
  //open3d::utility::PrintInfo("Open3D {}\n", OPEN3D_VERSION);
  open3d::PrintOpen3DVersion();
  EXPECT_EQ(OPEN3D_VERSION, "0.15.0");
}


TEST(SimpleOpen3DTest, SimpleTest) {
  auto pc = std::make_shared<open3d::geometry::PointCloud>();
  EXPECT_EQ(3, pc->Dimension());
}

TEST(SimpleOpen3DTest, ReadPointCloudTest) {
  auto pc = std::make_shared<open3d::geometry::PointCloud>();
  open3d::io::ReadPointCloud(resources_path + "/galleon.ply", *pc);
  EXPECT_EQ(3, pc->Dimension());
}

TEST(SimpleOpen3DTest, ReadTwoPointCloudTest) {
  auto pc1 = std::make_shared<open3d::geometry::PointCloud>();
  open3d::io::ReadPointCloud(resources_path + "/galleon.ply", *pc1);
  auto pc2 = std::make_shared<open3d::geometry::PointCloud>();
  open3d::io::ReadPointCloud(resources_path + "/balance.ply", *pc2);
  EXPECT_EQ(pc2->Dimension(), pc1->Dimension());
  EXPECT_NE(pc1->points_.size(), pc2->points_.size());
}


int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  if (argc > 1) {
    resources_path = std::string(argv[1]);
  }
  return RUN_ALL_TESTS();
}
