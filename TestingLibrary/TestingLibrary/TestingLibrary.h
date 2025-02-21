import AudioKit



public struct ReverbEffect: PedalboardEffect {
    public var dryWetMix: AUValue = 0.0
    public var feedback: AUValue = 0.0

    public init(dryWetMix: AUValue = 0.0, feedback: AUValue = 0.0) {
        self.dryWetMix = dryWetMix
        self.feedback = feedback
    }
    
    public func apply(to input: Node) -> Node {
        let reverb = CostelloReverb(input)
        reverb.feedback = feedback
        return reverb
    }
}


public struct DistortionEffect: PedalboardEffect {
    public var distortion: AUValue = 0.0

    public init(distortion: AUValue = 0.0) {
        self.distortion = distortion
    }
    
    public func apply(to input: Node) -> Node {
        let distortionEffect = Distortion(input)
        distortionEffect.distortion = distortion
        return distortionEffect
    }
}
