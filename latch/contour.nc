(G-CODE GENERATED BY FLATCAM v8.994 - www.flatcam.org - Version Date: 2020/11/7)

(Name: latch2_contour.gm1_cutout_cnc)
(Type: G-code from Geometry)
(Units: MM)

(Created on lunedì, 10 maggio 2021 at 12:04)

(This preprocessor is the default preprocessor used by FlatCAM.)
(It is made to work with MACH3 compatible motion controllers.)

(TOOL DIAMETER: 2.0 mm)
(Feedrate_XY: 60.0 mm/min)
(Feedrate_Z: 60.0 mm/min)
(Feedrate rapids 1500.0 mm/min)

(Z_Cut: -2.0 mm)
(DepthPerCut: 0.2 mm <=>10 passes)
(Z_Move: 2.0 mm)
(Z Start: None mm)
(Z End: 15.0 mm)
(X,Y End: 0.0000, 0.0000 mm)
(Steps per circle: 64)
(Preprocessor Geometry: default)

(X range:   -1.1000 ...   43.3656  mm)
(Y range:   -1.1000 ...   36.5584  mm)

(Spindle Speed: 15000.0 RPM)
G21
G90
G94

G01 F60.00

M5
G00 Z25.0000
G00 X0.0000 Y0.0000
T1
M6    
(MSG, Change to Tool Dia = 2.0000)
M0
G00 Z25.0000

M03 S3000.0
G01 F60.00
G00 X-1.1000 Y14.8292
G01 F60.00
G01 Z-0.2000
G01 F60.00
G01 X-1.1000 Y-0.0000
G01 X-1.0948 Y-0.1079
G01 X-1.0789 Y-0.2146
G01 X-1.0527 Y-0.3194
G01 X-1.0163 Y-0.4210
G01 X-0.9702 Y-0.5186
G01 X-0.9147 Y-0.6112
G01 X-0.8504 Y-0.6979
G01 X-0.7779 Y-0.7779
G01 X-0.6979 Y-0.8504
G01 X-0.6112 Y-0.9147
G01 X-0.5186 Y-0.9702
G01 X-0.4210 Y-1.0163
G01 X-0.3194 Y-1.0527
G01 X-0.2146 Y-1.0789
G01 X-0.1079 Y-1.0948
G01 X-0.0000 Y-1.1000
G01 X18.2328 Y-1.1000
G00 X18.2328 Y-1.1000
G01 F60.00
G01 Z-0.4000
G01 F60.00
G01 X-0.0000 Y-1.1000
G01 X-0.1079 Y-1.0948
G01 X-0.2146 Y-1.0789
G01 X-0.3194 Y-1.0527
G01 X-0.4210 Y-1.0163
G01 X-0.5186 Y-0.9702
G01 X-0.6112 Y-0.9147
G01 X-0.6979 Y-0.8504
G01 X-0.7779 Y-0.7779
G01 X-0.8504 Y-0.6979
G01 X-0.9147 Y-0.6112
G01 X-0.9702 Y-0.5186
G01 X-1.0163 Y-0.4210
G01 X-1.0527 Y-0.3194
G01 X-1.0789 Y-0.2146
G01 X-1.0948 Y-0.1079
G01 X-1.1000 Y-0.0000
G01 X-1.1000 Y14.8292
G00 X-1.1000 Y14.8292
G01 F60.00
G01 Z-0.6000
G01 F60.00
G01 X-1.1000 Y-0.0000
G01 X-1.0948 Y-0.1079
G01 X-1.0789 Y-0.2146
G01 X-1.0527 Y-0.3194
G01 X-1.0163 Y-0.4210
G01 X-0.9702 Y-0.5186
G01 X-0.9147 Y-0.6112
G01 X-0.8504 Y-0.6979
G01 X-0.7779 Y-0.7779
G01 X-0.6979 Y-0.8504
G01 X-0.6112 Y-0.9147
G01 X-0.5186 Y-0.9702
G01 X-0.4210 Y-1.0163
G01 X-0.3194 Y-1.0527
G01 X-0.2146 Y-1.0789
G01 X-0.1079 Y-1.0948
G01 X-0.0000 Y-1.1000
G01 X18.2328 Y-1.1000
G00 X18.2328 Y-1.1000
G01 F60.00
G01 Z-0.8000
G01 F60.00
G01 X-0.0000 Y-1.1000
G01 X-0.1079 Y-1.0948
G01 X-0.2146 Y-1.0789
G01 X-0.3194 Y-1.0527
G01 X-0.4210 Y-1.0163
G01 X-0.5186 Y-0.9702
G01 X-0.6112 Y-0.9147
G01 X-0.6979 Y-0.8504
G01 X-0.7779 Y-0.7779
G01 X-0.8504 Y-0.6979
G01 X-0.9147 Y-0.6112
G01 X-0.9702 Y-0.5186
G01 X-1.0163 Y-0.4210
G01 X-1.0527 Y-0.3194
G01 X-1.0789 Y-0.2146
G01 X-1.0948 Y-0.1079
G01 X-1.1000 Y-0.0000
G01 X-1.1000 Y14.8292
G00 X-1.1000 Y14.8292
G01 F60.00
G01 Z-1.0000
G01 F60.00
G01 X-1.1000 Y-0.0000
G01 X-1.0948 Y-0.1079
G01 X-1.0789 Y-0.2146
G01 X-1.0527 Y-0.3194
G01 X-1.0163 Y-0.4210
G01 X-0.9702 Y-0.5186
G01 X-0.9147 Y-0.6112
G01 X-0.8504 Y-0.6979
G01 X-0.7779 Y-0.7779
G01 X-0.6979 Y-0.8504
G01 X-0.6112 Y-0.9147
G01 X-0.5186 Y-0.9702
G01 X-0.4210 Y-1.0163
G01 X-0.3194 Y-1.0527
G01 X-0.2146 Y-1.0789
G01 X-0.1079 Y-1.0948
G01 X-0.0000 Y-1.1000
G01 X18.2328 Y-1.1000
G00 X18.2328 Y-1.1000
G01 F60.00
G01 Z-1.2000
G01 F60.00
G01 X-0.0000 Y-1.1000
G01 X-0.1079 Y-1.0948
G01 X-0.2146 Y-1.0789
G01 X-0.3194 Y-1.0527
G01 X-0.4210 Y-1.0163
G01 X-0.5186 Y-0.9702
G01 X-0.6112 Y-0.9147
G01 X-0.6979 Y-0.8504
G01 X-0.7779 Y-0.7779
G01 X-0.8504 Y-0.6979
G01 X-0.9147 Y-0.6112
G01 X-0.9702 Y-0.5186
G01 X-1.0163 Y-0.4210
G01 X-1.0527 Y-0.3194
G01 X-1.0789 Y-0.2146
G01 X-1.0948 Y-0.1079
G01 X-1.1000 Y-0.0000
G01 X-1.1000 Y14.8292
G00 X-1.1000 Y14.8292
G01 F60.00
G01 Z-1.4000
G01 F60.00
G01 X-1.1000 Y-0.0000
G01 X-1.0948 Y-0.1079
G01 X-1.0789 Y-0.2146
G01 X-1.0527 Y-0.3194
G01 X-1.0163 Y-0.4210
G01 X-0.9702 Y-0.5186
G01 X-0.9147 Y-0.6112
G01 X-0.8504 Y-0.6979
G01 X-0.7779 Y-0.7779
G01 X-0.6979 Y-0.8504
G01 X-0.6112 Y-0.9147
G01 X-0.5186 Y-0.9702
G01 X-0.4210 Y-1.0163
G01 X-0.3194 Y-1.0527
G01 X-0.2146 Y-1.0789
G01 X-0.1079 Y-1.0948
G01 X-0.0000 Y-1.1000
G01 X18.2328 Y-1.1000
G00 X18.2328 Y-1.1000
G01 F60.00
G01 Z-1.6000
G01 F60.00
G01 X-0.0000 Y-1.1000
G01 X-0.1079 Y-1.0948
G01 X-0.2146 Y-1.0789
G01 X-0.3194 Y-1.0527
G01 X-0.4210 Y-1.0163
G01 X-0.5186 Y-0.9702
G01 X-0.6112 Y-0.9147
G01 X-0.6979 Y-0.8504
G01 X-0.7779 Y-0.7779
G01 X-0.8504 Y-0.6979
G01 X-0.9147 Y-0.6112
G01 X-0.9702 Y-0.5186
G01 X-1.0163 Y-0.4210
G01 X-1.0527 Y-0.3194
G01 X-1.0789 Y-0.2146
G01 X-1.0948 Y-0.1079
G01 X-1.1000 Y-0.0000
G01 X-1.1000 Y14.8292
G00 X-1.1000 Y14.8292
G01 F60.00
G01 Z-1.8000
G01 F60.00
G01 X-1.1000 Y-0.0000
G01 X-1.0948 Y-0.1079
G01 X-1.0789 Y-0.2146
G01 X-1.0527 Y-0.3194
G01 X-1.0163 Y-0.4210
G01 X-0.9702 Y-0.5186
G01 X-0.9147 Y-0.6112
G01 X-0.8504 Y-0.6979
G01 X-0.7779 Y-0.7779
G01 X-0.6979 Y-0.8504
G01 X-0.6112 Y-0.9147
G01 X-0.5186 Y-0.9702
G01 X-0.4210 Y-1.0163
G01 X-0.3194 Y-1.0527
G01 X-0.2146 Y-1.0789
G01 X-0.1079 Y-1.0948
G01 X-0.0000 Y-1.1000
G01 X18.2328 Y-1.1000
G00 X18.2328 Y-1.1000
G01 F60.00
G01 Z-2.0000
G01 F60.00
G01 X-0.0000 Y-1.1000
G01 X-0.1079 Y-1.0948
G01 X-0.2146 Y-1.0789
G01 X-0.3194 Y-1.0527
G01 X-0.4210 Y-1.0163
G01 X-0.5186 Y-0.9702
G01 X-0.6112 Y-0.9147
G01 X-0.6979 Y-0.8504
G01 X-0.7779 Y-0.7779
G01 X-0.8504 Y-0.6979
G01 X-0.9147 Y-0.6112
G01 X-0.9702 Y-0.5186
G01 X-1.0163 Y-0.4210
G01 X-1.0527 Y-0.3194
G01 X-1.0789 Y-0.2146
G01 X-1.0948 Y-0.1079
G01 X-1.1000 Y-0.0000
G01 X-1.1000 Y14.8292
G00 Z2.0000
G00 X-1.1000 Y20.8292
G01 F60.00
G01 Z-0.2000
G01 F60.00
G01 X-1.1000 Y35.4584
G01 X-1.0948 Y35.5663
G01 X-1.0789 Y35.6730
G01 X-1.0527 Y35.7778
G01 X-1.0163 Y35.8794
G01 X-0.9702 Y35.9770
G01 X-0.9147 Y36.0696
G01 X-0.8504 Y36.1563
G01 X-0.7779 Y36.2363
G01 X-0.6979 Y36.3088
G01 X-0.6112 Y36.3731
G01 X-0.5186 Y36.4286
G01 X-0.4210 Y36.4747
G01 X-0.3194 Y36.5111
G01 X-0.2146 Y36.5373
G01 X-0.1079 Y36.5532
G01 X-0.0000 Y36.5584
G01 X18.2328 Y36.5584
G00 X18.2328 Y36.5584
G01 F60.00
G01 Z-0.4000
G01 F60.00
G01 X-0.0000 Y36.5584
G01 X-0.1079 Y36.5532
G01 X-0.2146 Y36.5373
G01 X-0.3194 Y36.5111
G01 X-0.4210 Y36.4747
G01 X-0.5186 Y36.4286
G01 X-0.6112 Y36.3731
G01 X-0.6979 Y36.3088
G01 X-0.7779 Y36.2363
G01 X-0.8504 Y36.1563
G01 X-0.9147 Y36.0696
G01 X-0.9702 Y35.9770
G01 X-1.0163 Y35.8794
G01 X-1.0527 Y35.7778
G01 X-1.0789 Y35.6730
G01 X-1.0948 Y35.5663
G01 X-1.1000 Y35.4584
G01 X-1.1000 Y20.8292
G00 X-1.1000 Y20.8292
G01 F60.00
G01 Z-0.6000
G01 F60.00
G01 X-1.1000 Y35.4584
G01 X-1.0948 Y35.5663
G01 X-1.0789 Y35.6730
G01 X-1.0527 Y35.7778
G01 X-1.0163 Y35.8794
G01 X-0.9702 Y35.9770
G01 X-0.9147 Y36.0696
G01 X-0.8504 Y36.1563
G01 X-0.7779 Y36.2363
G01 X-0.6979 Y36.3088
G01 X-0.6112 Y36.3731
G01 X-0.5186 Y36.4286
G01 X-0.4210 Y36.4747
G01 X-0.3194 Y36.5111
G01 X-0.2146 Y36.5373
G01 X-0.1079 Y36.5532
G01 X-0.0000 Y36.5584
G01 X18.2328 Y36.5584
G00 X18.2328 Y36.5584
G01 F60.00
G01 Z-0.8000
G01 F60.00
G01 X-0.0000 Y36.5584
G01 X-0.1079 Y36.5532
G01 X-0.2146 Y36.5373
G01 X-0.3194 Y36.5111
G01 X-0.4210 Y36.4747
G01 X-0.5186 Y36.4286
G01 X-0.6112 Y36.3731
G01 X-0.6979 Y36.3088
G01 X-0.7779 Y36.2363
G01 X-0.8504 Y36.1563
G01 X-0.9147 Y36.0696
G01 X-0.9702 Y35.9770
G01 X-1.0163 Y35.8794
G01 X-1.0527 Y35.7778
G01 X-1.0789 Y35.6730
G01 X-1.0948 Y35.5663
G01 X-1.1000 Y35.4584
G01 X-1.1000 Y20.8292
G00 X-1.1000 Y20.8292
G01 F60.00
G01 Z-1.0000
G01 F60.00
G01 X-1.1000 Y35.4584
G01 X-1.0948 Y35.5663
G01 X-1.0789 Y35.6730
G01 X-1.0527 Y35.7778
G01 X-1.0163 Y35.8794
G01 X-0.9702 Y35.9770
G01 X-0.9147 Y36.0696
G01 X-0.8504 Y36.1563
G01 X-0.7779 Y36.2363
G01 X-0.6979 Y36.3088
G01 X-0.6112 Y36.3731
G01 X-0.5186 Y36.4286
G01 X-0.4210 Y36.4747
G01 X-0.3194 Y36.5111
G01 X-0.2146 Y36.5373
G01 X-0.1079 Y36.5532
G01 X-0.0000 Y36.5584
G01 X18.2328 Y36.5584
G00 X18.2328 Y36.5584
G01 F60.00
G01 Z-1.2000
G01 F60.00
G01 X-0.0000 Y36.5584
G01 X-0.1079 Y36.5532
G01 X-0.2146 Y36.5373
G01 X-0.3194 Y36.5111
G01 X-0.4210 Y36.4747
G01 X-0.5186 Y36.4286
G01 X-0.6112 Y36.3731
G01 X-0.6979 Y36.3088
G01 X-0.7779 Y36.2363
G01 X-0.8504 Y36.1563
G01 X-0.9147 Y36.0696
G01 X-0.9702 Y35.9770
G01 X-1.0163 Y35.8794
G01 X-1.0527 Y35.7778
G01 X-1.0789 Y35.6730
G01 X-1.0948 Y35.5663
G01 X-1.1000 Y35.4584
G01 X-1.1000 Y20.8292
G00 X-1.1000 Y20.8292
G01 F60.00
G01 Z-1.4000
G01 F60.00
G01 X-1.1000 Y35.4584
G01 X-1.0948 Y35.5663
G01 X-1.0789 Y35.6730
G01 X-1.0527 Y35.7778
G01 X-1.0163 Y35.8794
G01 X-0.9702 Y35.9770
G01 X-0.9147 Y36.0696
G01 X-0.8504 Y36.1563
G01 X-0.7779 Y36.2363
G01 X-0.6979 Y36.3088
G01 X-0.6112 Y36.3731
G01 X-0.5186 Y36.4286
G01 X-0.4210 Y36.4747
G01 X-0.3194 Y36.5111
G01 X-0.2146 Y36.5373
G01 X-0.1079 Y36.5532
G01 X-0.0000 Y36.5584
G01 X18.2328 Y36.5584
G00 X18.2328 Y36.5584
G01 F60.00
G01 Z-1.6000
G01 F60.00
G01 X-0.0000 Y36.5584
G01 X-0.1079 Y36.5532
G01 X-0.2146 Y36.5373
G01 X-0.3194 Y36.5111
G01 X-0.4210 Y36.4747
G01 X-0.5186 Y36.4286
G01 X-0.6112 Y36.3731
G01 X-0.6979 Y36.3088
G01 X-0.7779 Y36.2363
G01 X-0.8504 Y36.1563
G01 X-0.9147 Y36.0696
G01 X-0.9702 Y35.9770
G01 X-1.0163 Y35.8794
G01 X-1.0527 Y35.7778
G01 X-1.0789 Y35.6730
G01 X-1.0948 Y35.5663
G01 X-1.1000 Y35.4584
G01 X-1.1000 Y20.8292
G00 X-1.1000 Y20.8292
G01 F60.00
G01 Z-1.8000
G01 F60.00
G01 X-1.1000 Y35.4584
G01 X-1.0948 Y35.5663
G01 X-1.0789 Y35.6730
G01 X-1.0527 Y35.7778
G01 X-1.0163 Y35.8794
G01 X-0.9702 Y35.9770
G01 X-0.9147 Y36.0696
G01 X-0.8504 Y36.1563
G01 X-0.7779 Y36.2363
G01 X-0.6979 Y36.3088
G01 X-0.6112 Y36.3731
G01 X-0.5186 Y36.4286
G01 X-0.4210 Y36.4747
G01 X-0.3194 Y36.5111
G01 X-0.2146 Y36.5373
G01 X-0.1079 Y36.5532
G01 X-0.0000 Y36.5584
G01 X18.2328 Y36.5584
G00 X18.2328 Y36.5584
G01 F60.00
G01 Z-2.0000
G01 F60.00
G01 X-0.0000 Y36.5584
G01 X-0.1079 Y36.5532
G01 X-0.2146 Y36.5373
G01 X-0.3194 Y36.5111
G01 X-0.4210 Y36.4747
G01 X-0.5186 Y36.4286
G01 X-0.6112 Y36.3731
G01 X-0.6979 Y36.3088
G01 X-0.7779 Y36.2363
G01 X-0.8504 Y36.1563
G01 X-0.9147 Y36.0696
G01 X-0.9702 Y35.9770
G01 X-1.0163 Y35.8794
G01 X-1.0527 Y35.7778
G01 X-1.0789 Y35.6730
G01 X-1.0948 Y35.5663
G01 X-1.1000 Y35.4584
G01 X-1.1000 Y20.8292
G00 Z2.0000
G00 X24.2328 Y36.5584
G01 F60.00
G01 Z-0.2000
G01 F60.00
G01 X42.2656 Y36.5584
G01 X42.3735 Y36.5532
G01 X42.4802 Y36.5373
G01 X42.5850 Y36.5111
G01 X42.6866 Y36.4747
G01 X42.7842 Y36.4286
G01 X42.8768 Y36.3731
G01 X42.9635 Y36.3088
G01 X43.0435 Y36.2363
G01 X43.1160 Y36.1563
G01 X43.1803 Y36.0696
G01 X43.2358 Y35.9770
G01 X43.2819 Y35.8794
G01 X43.3183 Y35.7778
G01 X43.3445 Y35.6730
G01 X43.3604 Y35.5663
G01 X43.3656 Y35.4584
G01 X43.3656 Y20.8292
G00 X43.3656 Y20.8292
G01 F60.00
G01 Z-0.4000
G01 F60.00
G01 X43.3656 Y35.4584
G01 X43.3604 Y35.5663
G01 X43.3445 Y35.6730
G01 X43.3183 Y35.7778
G01 X43.2819 Y35.8794
G01 X43.2358 Y35.9770
G01 X43.1803 Y36.0696
G01 X43.1160 Y36.1563
G01 X43.0435 Y36.2363
G01 X42.9635 Y36.3088
G01 X42.8768 Y36.3731
G01 X42.7842 Y36.4286
G01 X42.6866 Y36.4747
G01 X42.5850 Y36.5111
G01 X42.4802 Y36.5373
G01 X42.3735 Y36.5532
G01 X42.2656 Y36.5584
G01 X24.2328 Y36.5584
G00 X24.2328 Y36.5584
G01 F60.00
G01 Z-0.6000
G01 F60.00
G01 X42.2656 Y36.5584
G01 X42.3735 Y36.5532
G01 X42.4802 Y36.5373
G01 X42.5850 Y36.5111
G01 X42.6866 Y36.4747
G01 X42.7842 Y36.4286
G01 X42.8768 Y36.3731
G01 X42.9635 Y36.3088
G01 X43.0435 Y36.2363
G01 X43.1160 Y36.1563
G01 X43.1803 Y36.0696
G01 X43.2358 Y35.9770
G01 X43.2819 Y35.8794
G01 X43.3183 Y35.7778
G01 X43.3445 Y35.6730
G01 X43.3604 Y35.5663
G01 X43.3656 Y35.4584
G01 X43.3656 Y20.8292
G00 X43.3656 Y20.8292
G01 F60.00
G01 Z-0.8000
G01 F60.00
G01 X43.3656 Y35.4584
G01 X43.3604 Y35.5663
G01 X43.3445 Y35.6730
G01 X43.3183 Y35.7778
G01 X43.2819 Y35.8794
G01 X43.2358 Y35.9770
G01 X43.1803 Y36.0696
G01 X43.1160 Y36.1563
G01 X43.0435 Y36.2363
G01 X42.9635 Y36.3088
G01 X42.8768 Y36.3731
G01 X42.7842 Y36.4286
G01 X42.6866 Y36.4747
G01 X42.5850 Y36.5111
G01 X42.4802 Y36.5373
G01 X42.3735 Y36.5532
G01 X42.2656 Y36.5584
G01 X24.2328 Y36.5584
G00 X24.2328 Y36.5584
G01 F60.00
G01 Z-1.0000
G01 F60.00
G01 X42.2656 Y36.5584
G01 X42.3735 Y36.5532
G01 X42.4802 Y36.5373
G01 X42.5850 Y36.5111
G01 X42.6866 Y36.4747
G01 X42.7842 Y36.4286
G01 X42.8768 Y36.3731
G01 X42.9635 Y36.3088
G01 X43.0435 Y36.2363
G01 X43.1160 Y36.1563
G01 X43.1803 Y36.0696
G01 X43.2358 Y35.9770
G01 X43.2819 Y35.8794
G01 X43.3183 Y35.7778
G01 X43.3445 Y35.6730
G01 X43.3604 Y35.5663
G01 X43.3656 Y35.4584
G01 X43.3656 Y20.8292
G00 X43.3656 Y20.8292
G01 F60.00
G01 Z-1.2000
G01 F60.00
G01 X43.3656 Y35.4584
G01 X43.3604 Y35.5663
G01 X43.3445 Y35.6730
G01 X43.3183 Y35.7778
G01 X43.2819 Y35.8794
G01 X43.2358 Y35.9770
G01 X43.1803 Y36.0696
G01 X43.1160 Y36.1563
G01 X43.0435 Y36.2363
G01 X42.9635 Y36.3088
G01 X42.8768 Y36.3731
G01 X42.7842 Y36.4286
G01 X42.6866 Y36.4747
G01 X42.5850 Y36.5111
G01 X42.4802 Y36.5373
G01 X42.3735 Y36.5532
G01 X42.2656 Y36.5584
G01 X24.2328 Y36.5584
G00 X24.2328 Y36.5584
G01 F60.00
G01 Z-1.4000
G01 F60.00
G01 X42.2656 Y36.5584
G01 X42.3735 Y36.5532
G01 X42.4802 Y36.5373
G01 X42.5850 Y36.5111
G01 X42.6866 Y36.4747
G01 X42.7842 Y36.4286
G01 X42.8768 Y36.3731
G01 X42.9635 Y36.3088
G01 X43.0435 Y36.2363
G01 X43.1160 Y36.1563
G01 X43.1803 Y36.0696
G01 X43.2358 Y35.9770
G01 X43.2819 Y35.8794
G01 X43.3183 Y35.7778
G01 X43.3445 Y35.6730
G01 X43.3604 Y35.5663
G01 X43.3656 Y35.4584
G01 X43.3656 Y20.8292
G00 X43.3656 Y20.8292
G01 F60.00
G01 Z-1.6000
G01 F60.00
G01 X43.3656 Y35.4584
G01 X43.3604 Y35.5663
G01 X43.3445 Y35.6730
G01 X43.3183 Y35.7778
G01 X43.2819 Y35.8794
G01 X43.2358 Y35.9770
G01 X43.1803 Y36.0696
G01 X43.1160 Y36.1563
G01 X43.0435 Y36.2363
G01 X42.9635 Y36.3088
G01 X42.8768 Y36.3731
G01 X42.7842 Y36.4286
G01 X42.6866 Y36.4747
G01 X42.5850 Y36.5111
G01 X42.4802 Y36.5373
G01 X42.3735 Y36.5532
G01 X42.2656 Y36.5584
G01 X24.2328 Y36.5584
G00 X24.2328 Y36.5584
G01 F60.00
G01 Z-1.8000
G01 F60.00
G01 X42.2656 Y36.5584
G01 X42.3735 Y36.5532
G01 X42.4802 Y36.5373
G01 X42.5850 Y36.5111
G01 X42.6866 Y36.4747
G01 X42.7842 Y36.4286
G01 X42.8768 Y36.3731
G01 X42.9635 Y36.3088
G01 X43.0435 Y36.2363
G01 X43.1160 Y36.1563
G01 X43.1803 Y36.0696
G01 X43.2358 Y35.9770
G01 X43.2819 Y35.8794
G01 X43.3183 Y35.7778
G01 X43.3445 Y35.6730
G01 X43.3604 Y35.5663
G01 X43.3656 Y35.4584
G01 X43.3656 Y20.8292
G00 X43.3656 Y20.8292
G01 F60.00
G01 Z-2.0000
G01 F60.00
G01 X43.3656 Y35.4584
G01 X43.3604 Y35.5663
G01 X43.3445 Y35.6730
G01 X43.3183 Y35.7778
G01 X43.2819 Y35.8794
G01 X43.2358 Y35.9770
G01 X43.1803 Y36.0696
G01 X43.1160 Y36.1563
G01 X43.0435 Y36.2363
G01 X42.9635 Y36.3088
G01 X42.8768 Y36.3731
G01 X42.7842 Y36.4286
G01 X42.6866 Y36.4747
G01 X42.5850 Y36.5111
G01 X42.4802 Y36.5373
G01 X42.3735 Y36.5532
G01 X42.2656 Y36.5584
G01 X24.2328 Y36.5584
G00 Z2.0000
G00 X43.3656 Y14.8292
G01 F60.00
G01 Z-0.2000
G01 F60.00
G01 X43.3656 Y-0.0000
G01 X43.3604 Y-0.1079
G01 X43.3445 Y-0.2146
G01 X43.3183 Y-0.3194
G01 X43.2819 Y-0.4210
G01 X43.2358 Y-0.5186
G01 X43.1803 Y-0.6112
G01 X43.1160 Y-0.6979
G01 X43.0435 Y-0.7779
G01 X42.9635 Y-0.8504
G01 X42.8768 Y-0.9147
G01 X42.7842 Y-0.9702
G01 X42.6866 Y-1.0163
G01 X42.5850 Y-1.0527
G01 X42.4802 Y-1.0789
G01 X42.3735 Y-1.0948
G01 X42.2656 Y-1.1000
G01 X24.2328 Y-1.1000
G00 X24.2328 Y-1.1000
G01 F60.00
G01 Z-0.4000
G01 F60.00
G01 X42.2656 Y-1.1000
G01 X42.3735 Y-1.0948
G01 X42.4802 Y-1.0789
G01 X42.5850 Y-1.0527
G01 X42.6866 Y-1.0163
G01 X42.7842 Y-0.9702
G01 X42.8768 Y-0.9147
G01 X42.9635 Y-0.8504
G01 X43.0435 Y-0.7779
G01 X43.1160 Y-0.6979
G01 X43.1803 Y-0.6112
G01 X43.2358 Y-0.5186
G01 X43.2819 Y-0.4210
G01 X43.3183 Y-0.3194
G01 X43.3445 Y-0.2146
G01 X43.3604 Y-0.1079
G01 X43.3656 Y-0.0000
G01 X43.3656 Y14.8292
G00 X43.3656 Y14.8292
G01 F60.00
G01 Z-0.6000
G01 F60.00
G01 X43.3656 Y-0.0000
G01 X43.3604 Y-0.1079
G01 X43.3445 Y-0.2146
G01 X43.3183 Y-0.3194
G01 X43.2819 Y-0.4210
G01 X43.2358 Y-0.5186
G01 X43.1803 Y-0.6112
G01 X43.1160 Y-0.6979
G01 X43.0435 Y-0.7779
G01 X42.9635 Y-0.8504
G01 X42.8768 Y-0.9147
G01 X42.7842 Y-0.9702
G01 X42.6866 Y-1.0163
G01 X42.5850 Y-1.0527
G01 X42.4802 Y-1.0789
G01 X42.3735 Y-1.0948
G01 X42.2656 Y-1.1000
G01 X24.2328 Y-1.1000
G00 X24.2328 Y-1.1000
G01 F60.00
G01 Z-0.8000
G01 F60.00
G01 X42.2656 Y-1.1000
G01 X42.3735 Y-1.0948
G01 X42.4802 Y-1.0789
G01 X42.5850 Y-1.0527
G01 X42.6866 Y-1.0163
G01 X42.7842 Y-0.9702
G01 X42.8768 Y-0.9147
G01 X42.9635 Y-0.8504
G01 X43.0435 Y-0.7779
G01 X43.1160 Y-0.6979
G01 X43.1803 Y-0.6112
G01 X43.2358 Y-0.5186
G01 X43.2819 Y-0.4210
G01 X43.3183 Y-0.3194
G01 X43.3445 Y-0.2146
G01 X43.3604 Y-0.1079
G01 X43.3656 Y-0.0000
G01 X43.3656 Y14.8292
G00 X43.3656 Y14.8292
G01 F60.00
G01 Z-1.0000
G01 F60.00
G01 X43.3656 Y-0.0000
G01 X43.3604 Y-0.1079
G01 X43.3445 Y-0.2146
G01 X43.3183 Y-0.3194
G01 X43.2819 Y-0.4210
G01 X43.2358 Y-0.5186
G01 X43.1803 Y-0.6112
G01 X43.1160 Y-0.6979
G01 X43.0435 Y-0.7779
G01 X42.9635 Y-0.8504
G01 X42.8768 Y-0.9147
G01 X42.7842 Y-0.9702
G01 X42.6866 Y-1.0163
G01 X42.5850 Y-1.0527
G01 X42.4802 Y-1.0789
G01 X42.3735 Y-1.0948
G01 X42.2656 Y-1.1000
G01 X24.2328 Y-1.1000
G00 X24.2328 Y-1.1000
G01 F60.00
G01 Z-1.2000
G01 F60.00
G01 X42.2656 Y-1.1000
G01 X42.3735 Y-1.0948
G01 X42.4802 Y-1.0789
G01 X42.5850 Y-1.0527
G01 X42.6866 Y-1.0163
G01 X42.7842 Y-0.9702
G01 X42.8768 Y-0.9147
G01 X42.9635 Y-0.8504
G01 X43.0435 Y-0.7779
G01 X43.1160 Y-0.6979
G01 X43.1803 Y-0.6112
G01 X43.2358 Y-0.5186
G01 X43.2819 Y-0.4210
G01 X43.3183 Y-0.3194
G01 X43.3445 Y-0.2146
G01 X43.3604 Y-0.1079
G01 X43.3656 Y-0.0000
G01 X43.3656 Y14.8292
G00 X43.3656 Y14.8292
G01 F60.00
G01 Z-1.4000
G01 F60.00
G01 X43.3656 Y-0.0000
G01 X43.3604 Y-0.1079
G01 X43.3445 Y-0.2146
G01 X43.3183 Y-0.3194
G01 X43.2819 Y-0.4210
G01 X43.2358 Y-0.5186
G01 X43.1803 Y-0.6112
G01 X43.1160 Y-0.6979
G01 X43.0435 Y-0.7779
G01 X42.9635 Y-0.8504
G01 X42.8768 Y-0.9147
G01 X42.7842 Y-0.9702
G01 X42.6866 Y-1.0163
G01 X42.5850 Y-1.0527
G01 X42.4802 Y-1.0789
G01 X42.3735 Y-1.0948
G01 X42.2656 Y-1.1000
G01 X24.2328 Y-1.1000
G00 X24.2328 Y-1.1000
G01 F60.00
G01 Z-1.6000
G01 F60.00
G01 X42.2656 Y-1.1000
G01 X42.3735 Y-1.0948
G01 X42.4802 Y-1.0789
G01 X42.5850 Y-1.0527
G01 X42.6866 Y-1.0163
G01 X42.7842 Y-0.9702
G01 X42.8768 Y-0.9147
G01 X42.9635 Y-0.8504
G01 X43.0435 Y-0.7779
G01 X43.1160 Y-0.6979
G01 X43.1803 Y-0.6112
G01 X43.2358 Y-0.5186
G01 X43.2819 Y-0.4210
G01 X43.3183 Y-0.3194
G01 X43.3445 Y-0.2146
G01 X43.3604 Y-0.1079
G01 X43.3656 Y-0.0000
G01 X43.3656 Y14.8292
G00 X43.3656 Y14.8292
G01 F60.00
G01 Z-1.8000
G01 F60.00
G01 X43.3656 Y-0.0000
G01 X43.3604 Y-0.1079
G01 X43.3445 Y-0.2146
G01 X43.3183 Y-0.3194
G01 X43.2819 Y-0.4210
G01 X43.2358 Y-0.5186
G01 X43.1803 Y-0.6112
G01 X43.1160 Y-0.6979
G01 X43.0435 Y-0.7779
G01 X42.9635 Y-0.8504
G01 X42.8768 Y-0.9147
G01 X42.7842 Y-0.9702
G01 X42.6866 Y-1.0163
G01 X42.5850 Y-1.0527
G01 X42.4802 Y-1.0789
G01 X42.3735 Y-1.0948
G01 X42.2656 Y-1.1000
G01 X24.2328 Y-1.1000
G00 X24.2328 Y-1.1000
G01 F60.00
G01 Z-2.0000
G01 F60.00
G01 X42.2656 Y-1.1000
G01 X42.3735 Y-1.0948
G01 X42.4802 Y-1.0789
G01 X42.5850 Y-1.0527
G01 X42.6866 Y-1.0163
G01 X42.7842 Y-0.9702
G01 X42.8768 Y-0.9147
G01 X42.9635 Y-0.8504
G01 X43.0435 Y-0.7779
G01 X43.1160 Y-0.6979
G01 X43.1803 Y-0.6112
G01 X43.2358 Y-0.5186
G01 X43.2819 Y-0.4210
G01 X43.3183 Y-0.3194
G01 X43.3445 Y-0.2146
G01 X43.3604 Y-0.1079
G01 X43.3656 Y-0.0000
G01 X43.3656 Y14.8292
G00 Z2.0000
M05
G00 Z2.0000
G00 Z15.00
G00 X0.0 Y0.0

