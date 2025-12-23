import Engine from "../../loader/engine";

class BasicTest extends Engine {

    constructor(canvas: HTMLCanvasElement) {
        super(canvas);
    }

    onCreate(): boolean {
        alert(`From c++: 3 + 3 is ${this.g?._sum(3, 3)}`);
        return true;
    }

}

const main = async() => {
    const canvas = document.getElementById("gl") as HTMLCanvasElement;
    const engine = new BasicTest(canvas);
    engine.start();
}

addEventListener("load", main);

