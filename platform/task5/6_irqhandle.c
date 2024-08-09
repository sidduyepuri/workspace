#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

#define GPIO_INPUT_PIN 48  // GPIO1_16 (P9_15)
#define GPIO_OUTPUT_PIN 60 // GPIO1_28 (P9_12)

static unsigned int irqNumber;
static int irq_counter = 0;

// Interrupt handler function
static irqreturn_t gpio_isr(int irq, void *dev_id) {
	irq_counter++;
	printk(KERN_INFO"System Interrupted, hello from gpio_isr\n");
	printk(KERN_INFO "GPIO Interrupt! IRQ: %d Count: %d\n", irq, irq_counter);
	return IRQ_HANDLED;
}

static int __init gpio_irq_init(void) {
	int result = 0;

	// Request the GPIO pins
	if (!gpio_is_valid(GPIO_INPUT_PIN) || !gpio_is_valid(GPIO_OUTPUT_PIN)) {
		printk(KERN_ALERT "GPIO_TEST: invalid GPIO\n");
		return -ENODEV;
	}

	gpio_request(GPIO_INPUT_PIN, "sysfs");
	gpio_direction_input(GPIO_INPUT_PIN);
	gpio_export(GPIO_INPUT_PIN, false);

	gpio_request(GPIO_OUTPUT_PIN, "sysfs");
	gpio_direction_output(GPIO_OUTPUT_PIN, 0); // Initialize output pin to low
	gpio_export(GPIO_OUTPUT_PIN, false);

	// Set the edge detection for the input GPIO pin
	result = gpio_set_debounce(GPIO_INPUT_PIN, 200);  // Optional: set debounce time to 200ms
	if (result) {
		printk(KERN_ALERT "GPIO_TEST: cannot set debounce\n");
		return result;
	}

	// Map GPIO to IRQ
	irqNumber = gpio_to_irq(GPIO_INPUT_PIN);
	printk(KERN_INFO "GPIO_TEST: The GPIO %d is mapped to IRQ: %d\n", GPIO_INPUT_PIN, irqNumber);

	// Request IRQ
	result = request_irq(irqNumber, (irq_handler_t) gpio_isr, IRQF_TRIGGER_RISING, "gpio_handler", NULL);
	if (result) {
		printk(KERN_ALERT "GPIO_TEST: cannot request IRQ: %d\n", irqNumber);
		return result;
	}
	printk(KERN_INFO "GPIO_TEST: IRQ request successful.\n");

	return 0;
}

static void __exit gpio_irq_exit(void) {
	free_irq(irqNumber, NULL);
	gpio_unexport(GPIO_INPUT_PIN);
	gpio_free(GPIO_INPUT_PIN);
	gpio_unexport(GPIO_OUTPUT_PIN);
	gpio_free(GPIO_OUTPUT_PIN);
	printk(KERN_INFO "GPIO_TEST: Module exiting.\n");
}

module_init(gpio_irq_init);
module_exit(gpio_irq_exit);

MODULE_LICENSE("GPL");
