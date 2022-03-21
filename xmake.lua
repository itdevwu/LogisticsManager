-- Copyright 2022 Zhenglong WU(itdevwu)

add_requires("sqlite3 3.37.0")

target("UserAPPV1")
    -- set_kind("binary")
    add_rules("qt.widgetapp")
    set_languages("cxx20")
    add_packages("sqlite3")
    add_files("src/app/v1/*.cpp")
    add_files("src/app/v1/*.hpp")
    add_files("src/app/v1/*.ui")
