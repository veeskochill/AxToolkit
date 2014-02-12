project "RSquareDiamond"
   kind "ConsoleApp"
   language "C++"
   includedirs { "include" }
   files { "include/**.h", "src/**.cpp" }

   configuration "Debug"
      flags { "Symbols" }
      defines { "_DEBUG" }