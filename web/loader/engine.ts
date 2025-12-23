export default abstract class Engine {

    protected g: iZephyrus | null = null;     // core engine wasm

    protected constructor(canvas: HTMLCanvasElement) {

    }

    abstract onCreate(): boolean;

    private async init() {
        this.g = (await Zephyrus()) as iZephyrus;
    }

    public async start(): Promise<boolean> {
        await this.init();
        this.onCreate();
        return Promise.resolve(true);
    }
}
