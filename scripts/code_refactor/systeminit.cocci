@drop_nvic_setting@
expression e;
@@

void SystemInit (void)
{
...
- SCB->VTOR = e;
...
}