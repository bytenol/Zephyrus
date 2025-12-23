import Engine from "../../loader/engine";

class BasicTest extends Engine {

    constructor() {
        super("#gl");
    }

    onCreate(): boolean {
        // const g = new this.g?.
        console.log(this.g);
        return true;
    }

}

const main = async() => {
    const engine = new BasicTest();
    await engine.start();
}

addEventListener("load", main);

