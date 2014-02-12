solution "AxToolkit"
   configurations { "Debug" }

    local subdirs = os.matchdirs('./*')
    assert(#subdirs ~= 0, "No projects found for this solution.")
    for _, dir in pairs(subdirs) do
        local solutionScript = './' .. dir .. '/' .. dir .. '-Premake.lua'
	if(os.isfile(solutionScript)) then
		dofile(solutionScript)
	end
    end