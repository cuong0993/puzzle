/*************************************************************************/
/*  dummy.cpp                                                            */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#if defined(__arm__) || defined(__arm64__) || defined(__aarch64__)
#define IOS_DEVICE
#endif
#ifdef IOS_DEVICE
extern "C" {
// Mono API

typedef enum {
MONO_AOT_MODE_NONE,
MONO_AOT_MODE_NORMAL,
MONO_AOT_MODE_HYBRID,
MONO_AOT_MODE_FULL,
MONO_AOT_MODE_LLVMONLY,
MONO_AOT_MODE_INTERP,
MONO_AOT_MODE_INTERP_LLVMONLY,
MONO_AOT_MODE_LLVMONLY_INTERP,
MONO_AOT_MODE_LAST = 1000,
} MonoAotMode;
void mono_jit_set_aot_mode(MonoAotMode);
void mono_aot_register_module(void *);
void mono_ee_interp_init(const char *);
void mono_icall_table_init();
void mono_marshal_ilgen_init();
void mono_method_builder_ilgen_init();
void mono_sgen_mono_ilgen_init();
extern void *mono_aot_module_Puzzle_info;
extern void *mono_aot_module_mscorlib_info;
extern void *mono_aot_module_GodotSharp_info;
extern void *mono_aot_module_netstandard_info;
extern void *mono_aot_module_System_Core_info;
extern void *mono_aot_module_System_info;
extern void *mono_aot_module_Mono_Security_info;
extern void *mono_aot_module_System_Xml_info;
extern void *mono_aot_module_System_Numerics_info;
extern void *mono_aot_module_System_Data_info;
extern void *mono_aot_module_System_Transactions_info;
extern void *mono_aot_module_System_Data_DataSetExtensions_info;
extern void *mono_aot_module_System_Drawing_Common_info;
extern void *mono_aot_module_System_IO_Compression_info;
extern void *mono_aot_module_System_IO_Compression_FileSystem_info;
extern void *mono_aot_module_System_ComponentModel_Composition_info;
extern void *mono_aot_module_System_Net_Http_info;
extern void *mono_aot_module_I18N_info;
extern void *mono_aot_module_I18N_CJK_info;
extern void *mono_aot_module_I18N_MidEast_info;
extern void *mono_aot_module_I18N_Other_info;
extern void *mono_aot_module_I18N_Rare_info;
extern void *mono_aot_module_I18N_West_info;
void gd_mono_setup_aot() {
	mono_aot_register_module(mono_aot_module_Puzzle_info);
	mono_aot_register_module(mono_aot_module_mscorlib_info);
	mono_aot_register_module(mono_aot_module_GodotSharp_info);
	mono_aot_register_module(mono_aot_module_netstandard_info);
	mono_aot_register_module(mono_aot_module_System_Core_info);
	mono_aot_register_module(mono_aot_module_System_info);
	mono_aot_register_module(mono_aot_module_Mono_Security_info);
	mono_aot_register_module(mono_aot_module_System_Xml_info);
	mono_aot_register_module(mono_aot_module_System_Numerics_info);
	mono_aot_register_module(mono_aot_module_System_Data_info);
	mono_aot_register_module(mono_aot_module_System_Transactions_info);
	mono_aot_register_module(mono_aot_module_System_Data_DataSetExtensions_info);
	mono_aot_register_module(mono_aot_module_System_Drawing_Common_info);
	mono_aot_register_module(mono_aot_module_System_IO_Compression_info);
	mono_aot_register_module(mono_aot_module_System_IO_Compression_FileSystem_info);
	mono_aot_register_module(mono_aot_module_System_ComponentModel_Composition_info);
	mono_aot_register_module(mono_aot_module_System_Net_Http_info);
	mono_aot_register_module(mono_aot_module_I18N_info);
	mono_aot_register_module(mono_aot_module_I18N_CJK_info);
	mono_aot_register_module(mono_aot_module_I18N_MidEast_info);
	mono_aot_register_module(mono_aot_module_I18N_Other_info);
	mono_aot_register_module(mono_aot_module_I18N_Rare_info);
	mono_aot_register_module(mono_aot_module_I18N_West_info);
	mono_icall_table_init();
	mono_marshal_ilgen_init();
	mono_method_builder_ilgen_init();
	mono_sgen_mono_ilgen_init();
	mono_ee_interp_init(0);
	mono_jit_set_aot_mode(MONO_AOT_MODE_INTERP);
} // gd_mono_setup_aot
} // extern "C"
#endif // IOS_DEVICE

// Godot Plugins
void godot_ios_plugins_initialize();
void godot_ios_plugins_deinitialize();
// Exported Plugins

// Use Plugins
void godot_ios_plugins_initialize() {
}

void godot_ios_plugins_deinitialize() {
}


