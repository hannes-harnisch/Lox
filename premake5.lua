out_dir = '%{cfg.buildcfg}_%{cfg.architecture}_%{cfg.system}'

workspace 'Lox'
	startproject		'Lox1'
	architecture		'x64'
	configurations		{ 'Debug', 'Release' }
	flags				'MultiProcessorCompile'
	language			'C++'
	cppdialect			'C++20'
	staticruntime		'On'
	conformancemode		'On'
	inheritdependencies	'Off'
	warnings			'Extra'
	objdir				('.bin_int/' .. out_dir .. '/%{prj.name}')
	targetdir			('.bin/'	 .. out_dir .. '/%{prj.name}')
	debugdir			('.bin/'	 .. out_dir .. '/%{prj.name}')
	files				{
							'%{prj.name}/**.cpp',
							'%{prj.name}/**.hpp',
						}

	filter 'Debug'
		symbols			'On'
		runtime			'Debug'
		defines			'AX_DEBUG'

	filter 'Release'
		optimize		'Speed'
		runtime			'Release'
		flags			'LinkTimeOptimization'

project 'Lox1'
	location			'Lox1'
	kind				'ConsoleApp'
	pchheader			'PCH.hpp'
	pchsource			'%{prj.name}/PCH.cpp'