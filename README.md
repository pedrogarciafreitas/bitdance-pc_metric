# BitDance PCQA Metric

BitDance: Low Complexity Point Cloud Quality Assessment Metric

BitDance is a fast, OpenMP optimized implementation of ((mention article name and reference when published))

## Compilation

This code depends on the Open3D library: https://github.com/intel-isl/Open3D

## Usage

Prior to the execution of the metric, normals without ambiguities need to be created. For this use:

    create_normals point_cloud.ply pc_with_normals.ply

In order to obtain the target voxel edge size of a PC, given a "k" constant ("k" equals to 6.0 in
the article), using the average distance of 8 nearest neighbors (hardcoded in the code) as
reference, as described in the article, use:

    optimize_voxel_size 3 k point_cloud.ply

To run the CIEDE2000 color-based feature extractor with 8 bits label, neighborhood size of 12,
voxel size (use the output of optimize_voxel_size) "E", with the results written to "results-c.csv",  use:

    bitdance_pcqa -i point_cloud.ply -n 12 -m 0,1,0,0,0 -v E -h results-c.csv

To run the geometry-based feature extractor with label of 16-bit, neighborhood size of 6, without the
use of voxelization (voxelization does not help for the geometry-based feature extractor), with
results written to "results-g.csv", use:

    bitdance_pcqa -i pc_with_normals.ply -n 6 -m 0,0,1,0,0 -h results-g.csv


## Author

Rafael Diniz (rafael@riseup.net)

## Acknowledgments

- Mylene C.Q. Farias, my PhD advisor

- Pedro Garcia Freitas, my PhD co-advisor

- Open3D by Qian-Yi Zhou and Jaesik Park and Vladlen Koltun: http://open3d.org/

- Color spaces conversion code by Nicolae Berendea: https://github.com/berendeanicolae/ColorSpace

- Financial support by the following Brazilian agencies: CAPES and FAP-DF

## License

This code is licensed under GNU General Public License version 3 or any higher version, while the
color spaces conversion and the Open3D code are MIT licensed.
