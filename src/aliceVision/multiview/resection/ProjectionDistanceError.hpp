// This file is part of the AliceVision project.
// Copyright (c) 2016 AliceVision contributors.
// Copyright (c) 2012 openMVG contributors.
// This Source Code Form is subject to the terms of the Mozilla Public License,
// v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <aliceVision/multiview/ISolver.hpp>
#include <aliceVision/multiview/projection.hpp>

namespace aliceVision {
namespace multiview {
namespace resection {

/**
 * @brief Compute the residual of the projection distance
 *        (pt2D, Project(P,pt3D))
 */
struct ProjectionDistanceError : public ISolverErrorResection<Mat34Model>
{
  inline double error(const Mat34Model& P, const Vec2& p2d, const Vec3& p3d) const override
  {
    return (Project(P.getMatrix(), p3d) - p2d).norm();
  }
};

/**
 * @brief Compute the residual of the projection distance
 *        (pt2D, Project(P,pt3D))
 */
struct ProjectionDistanceSquaredError : public ISolverErrorResection<Mat34Model>
{
  inline double error(const Mat34Model& P, const Vec2& p2d, const Vec3& p3d) const override
  {
    return (Project(P.getMatrix(), p3d) - p2d).squaredNorm();
  }
};

}  // namespace resection
}  // namespace multiview
}  // namespace aliceVision
