import esphome.codegen as cg
import esphome.config_validation as cv

from esphome.components import display

AUTO_LOAD = ["display"]

DEPENDENCIES = []

guition_ns = cg.esphome_ns.namespace("guition_display")

GuitionDisplay = guition_ns.class_(
    "GuitionDisplay",
    cg.PollingComponent,
    display.DisplayBuffer,
)

CONFIG_SCHEMA = display.FULL_DISPLAY_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(GuitionDisplay),
    }
).extend(cv.polling_component_schema("1s"))


async def to_code(config):
    var = cg.new_Pvariable(config[cv.GenerateID()])

    await cg.register_component(var, config)

    # ⚠️ КЛЮЧОВА ПРОМЯНА:
    await display.register_display(var, config)
