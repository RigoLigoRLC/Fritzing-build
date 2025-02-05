# Copyright (c) 2021 Fritzing GmbH

message("Using fritzing svgpp detect script.")

exists($$absolute_path($$_PRO_FILE_PWD_/../svgpp-1.3.1)) {
                        SVGPPPATH = $$absolute_path($$_PRO_FILE_PWD_/../svgpp-1.3.1)
			message("found svgpp in $${SVGPPPATH}")
		}

message("including $$absolute_path($${SVGPPPATH}/include)")
INCLUDEPATH += $$absolute_path($${SVGPPPATH}/include)
