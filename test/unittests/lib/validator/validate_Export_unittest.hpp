#include <skypat/skypat.h>

#define _Bool bool
extern "C" {
#include <stdint.h>
#include <stdlib.h>
#include <dataTypes/Value.h>
#include <dataTypes/DescType.h>
#include <structures/WasmExport.h>
#include <structures/WasmFunc.h>
#include <structures/WasmTable.h>
#include <structures/WasmMemory.h>
#include <structures/WasmGlobal.h>
#include <Validates.h>
}
#undef _Bool

SKYPAT_F(Validate_Export, valid_func)
{
    // Prepare
    WasmExport* wasmExport = (WasmExport*)malloc(sizeof(WasmExport));
    WasmModule* module = new_WasmModule(NULL);
    module->funcs->push_back(module->funcs, new_WasmFunc());
    wasmExport->descType = Desc_Func;
    wasmExport->descIdx = 0;

    // Check
    EXPECT_EQ(validate_Export(wasmExport, module), 0);

    free(wasmExport);
    free_WasmModule(module);
}

SKYPAT_F(Validate_Export, func_not_defined)
{
    // Prepare
    WasmExport* wasmExport = (WasmExport*)malloc(sizeof(WasmExport));
    WasmModule* module = new_WasmModule(NULL);
    module->funcs->push_back(module->funcs, new_WasmFunc());
    wasmExport->descType = Desc_Func;
    wasmExport->descIdx = 1;

    // Check
    EXPECT_NE(validate_Export(wasmExport, module), 0);

    free(wasmExport);
    free_WasmModule(module);
}

SKYPAT_F(Validate_Export, valid_table)
{
    // Prepare
    WasmExport* wasmExport = (WasmExport*)malloc(sizeof(WasmExport));
    WasmModule* module = new_WasmModule(NULL);
    module->tables->push_back(module->tables, malloc(sizeof(WasmTable)));
    wasmExport->descType = Desc_Table;
    wasmExport->descIdx = 0;

    // Check
    EXPECT_EQ(validate_Export(wasmExport, module), 0);

    free(wasmExport);
    free_WasmModule(module);
}

SKYPAT_F(Validate_Export, table_not_defined)
{
    // Prepare
    WasmExport* wasmExport = (WasmExport*)malloc(sizeof(WasmExport));
    WasmModule* module = new_WasmModule(NULL);
    module->tables->push_back(module->tables, malloc(sizeof(WasmTable)));
    wasmExport->descType = Desc_Table;
    wasmExport->descIdx = 1;

    // Check
    EXPECT_NE(validate_Export(wasmExport, module), 0);

    free(wasmExport);
    free_WasmModule(module);
}

SKYPAT_F(Validate_Export, valid_memory)
{
    // Prepare
    WasmExport* wasmExport = (WasmExport*)malloc(sizeof(WasmExport));
    WasmModule* module = new_WasmModule(NULL);
    module->mems->push_back(module->mems, malloc(sizeof(WasmMemory)));
    wasmExport->descType = Desc_Mem;
    wasmExport->descIdx = 0;

    // Check
    EXPECT_EQ(validate_Export(wasmExport, module), 0);

    free(wasmExport);
    free_WasmModule(module);
}

SKYPAT_F(Validate_Export, momory_not_defined)
{
    // Prepare
    WasmExport* wasmExport = (WasmExport*)malloc(sizeof(WasmExport));
    WasmModule* module = new_WasmModule(NULL);
    module->mems->push_back(module->mems, malloc(sizeof(WasmMemory)));
    wasmExport->descType = Desc_Mem;
    wasmExport->descIdx = 1;

    // Check
    EXPECT_NE(validate_Export(wasmExport, module), 0);

    free(wasmExport);
    free_WasmModule(module);
}

SKYPAT_F(Validate_Export, valid_global)
{
    // Prepare
    WasmExport* wasmExport = (WasmExport*)malloc(sizeof(WasmExport));
    WasmModule* module = new_WasmModule(NULL);
    module->globals->push_back(module->globals, malloc(sizeof(WasmGlobal)));
    wasmExport->descType = Desc_Global;
    wasmExport->descIdx = 0;

    // Check
    EXPECT_EQ(validate_Export(wasmExport, module), 0);

    free(wasmExport);
    free_WasmModule(module);
}

SKYPAT_F(Validate_Export, global_not_defined)
{
    // Prepare
    WasmExport* wasmExport = (WasmExport*)malloc(sizeof(WasmExport));
    WasmModule* module = new_WasmModule(NULL);
    module->globals->push_back(module->globals, malloc(sizeof(WasmGlobal)));
    wasmExport->descType = Desc_Global;
    wasmExport->descIdx = 1;

    // Check
    EXPECT_NE(validate_Export(wasmExport, module), 0);

    free(wasmExport);
    free_WasmModule(module);
}