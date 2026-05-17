import torch

def main():
    print("Pytorch version:", torch.__version__)
    print("CUDA avaliable:", torch.cuda.is_available())

    x = torch.randn(2, 3)
    w = torch.randn(3, 4, requires_grad = True) # ask for gradient

    y = x @ w 
    loss = y.pow(2).mean()
    loss.backward()

    print("x.shape:", x.shape)
    print("w shape:", w.shape)
    print("loss", loss.item())
    print("w.grad shape:", w.grad.shape)

if __name__ == "__main__":
    main()