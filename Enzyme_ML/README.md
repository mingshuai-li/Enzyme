# Use Enzyme in ML Frameworks
For ML Frameworks, Enzyme already offers additional plugins for PyTorch and TensorFlow, enabling users of these ML frameworks to seamlessly import pre-existing C/C++ programs without the need for extensive rewriting. 

First, specify the desired gradient by calling __enzyme_autodiff as shown
```C
void f(float* inp, size_t n, float* out); // Input tensor + size, and output tensor
void diffef(float* inp, float* d_inp, size_t n, float* d_out) {
// enzyme_dupnoneed specifies not recomputing the output
__enzyme_autodiff(f, enzyme_dup, inp, d_inp, n, enzyme_dupnoneed, (float*)0, d_out);
}
```

Then we can use Enzyme to provide gradients of foreign code in PyTorch
```python
import torch
from torch_enzyme import enzyme
# Create some initial tensor
inp = ...
# Apply foreign function to tensor
out = enzyme("test.c", "f").apply(inp)
# Derive gradient
out.backward()
print(inp.grad)
```
In TensorFlow is similar
```python
import tensorflow as tf
from tf_enzyme import enzyme
inp = tf.Variable(...)
# Use external C code as a regular TF op
out = enzyme(inp, filename="test.c",
function="f")
# Results is a TF tensor
out = tf.sigmoid(out)
```

Enzyme also provides custom bindings within JAX. Besides, various frameworks can embed Enzyme with the custom operator capability of AI frameworks. 
Use MindSpore as an example, and the method is as follows:

1) Custom forward operator Enzyme by actively invoking clang to generate a shared object (.so) file from the foreign source code path. The generated .so file is then loaded using the dlfcn library to obtain and execute the forward function based on the provided function name.

2) Customise the reverse operator EnzymeGrad by actively utilizing Clang and Enzyme to generate a shared object (.so) file from the foreign source code path through AD. The generated .so file is then loaded using the dlfcn library to retrieve and execute the gradient function based on the specified function name.

3) Define the backpropagation function (bprop), the logic of which is to call the custom backpropagation operator EnzymeGrad. Define the forward network, which calls the custom Enzyme operator.

4) Finally, Enzyme actively calls the GradOperation function according to the forward network to generate the gradient
   
Then can use as follows:
```python
import mindspore,nn as nn
import mindspore.ops as ops

class EnzymeNet(nn.Cell):
  def _init_ (self):
    super(EnzymeNet,self)._init_()
    self.enzyme = ops.Enzyme()
    
  def construct(self, input, filename, function):
    return self.enzyme(input, filename, function)

class Grad(nn.Cell):
  def _init_(self,network):
    super(Grad,self)._init_()
    self.grad = ops.Gradoperation()
    self.network = network
def construct(self, input, filename, function):
  gout = self.grad(self.network)(input, filename, function)
  return gout
  
def test_grad net():
  inp = ...
  grad = Grad(EnzymeNet())
  out = grad(inp,"test .c", "f")
  print(out)
```
## References
[TensorFlow Contributors](https://www.tensorflow.org/guide/create_op)

[Torch Contributors](https://pytorch.org/tutorials/advanced/torch_script_custom_ops.html)

[MindSpore_Contributors, especially its architect Xuefeng Jin](https://www.mindspore.cn/tutorial/training/en/r1.1/advanced_use/custom_operator_cpu.html)
